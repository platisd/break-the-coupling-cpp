# Break the coupling (in C++)

Implementations tightly coupled to their dependencies are difficult to maintain,
reuse and test.

In this repository, I will show you 5 ways of refactoring with the intent to 
"break" tight coupling between business logic and dependencies.
A good indicator over the effectiveness of a decoupling is testability: If you are
able to test your class and your class only without being influenced by the inner
works of the various dependencies, then you know you have done a good decoupling.

Below you will find some tightly coupled code and several ways to break it away from
its dependencies. The focus will be mostly on the code, however, the build configuration
is often also very important. Being decoupled on the code level but not in the
CMake/Bazel/Blueprint files will not get you very far. Last but not least, for every
refactored example you will find the unit tests that accompany it.

## Tightly coupled code example

Here is some typical code that is coupled with its dependencies.

### [CameraPowerController.h](src/camera_power_controller/include/CameraPowerController.h)

```cpp
class CameraPowerController
{
public:
    CameraPowerController(ProductVariant productVariant);

    void turnOnCamera();
    void turnOffCamera();

private:
    std::unique_ptr<AsioSerialPortManager> mSerialPortManager;
};
```

`AsioSerialPortManager`, as its name implies, is a concrete class that utilizes a
[3rd-party library](https://github.com/chriskohlhoff/asio).

### [CameraPowerController.cpp](src/camera_power_controller/src/CameraPowerController.cpp)

```cpp
CameraPowerController::CameraPowerController(ProductVariant productVariant)
{
    switch (productVariant)
    {
    case ProductVariant::A:
        mSerialPortManager = std::make_unique<AsioSerialPortManager>(
            kSerialDevicePathForVariantA, kBaudRateForVariantA);
        return;
    case ProductVariant::B:
        mSerialPortManager = std::make_unique<AsioSerialPortManager>(
            kSerialDevicePathForVariantB, kBaudRateForVariantB);
        return;
    default:
        throw std::logic_error("Unknown variant");
    }
}

void CameraPowerController::turnOnCamera()
{
    mSerialPortManager->asioWrite("ON");
}
```

In the `CameraPowerController` implementation, we invoke the constructor of `AsioSerialPortManager`
with some arguments. These arguments are determined based on logic residing within the class. Then,
we call the instantiated class in the other member functions.

Whenever we invoke constructors of other classes, we become get coupled to them. In fact, this is
very often a red flag in regards to the testability of the class. Testability is decreased
because we become obliged to indirectly test them as well along with the unit we actual want to test.
Moreover, compiling and running a binary that involves them may be cumbersome or even impossible in
our unit testing environment.

For example, the particular classes may not be compilable for the host platform that runs the
unit tests. This is common when dependencies include resources that are precompiled for a different
operating system or architecture. Additionally, even if the dependant classes are compilable, it
may be impossible to execute them on our host platform, due to them requiring some specific resources
that are only found on a *target* system. In our case, the `AsioSerialPortManager` class needs to
open a connection to a serial device that will only exist on the target we are developing for and not
on the developer's computer.

In other words, if we would like to unit test our `CameraPowerController` class and have the unit tests
run on our development machines there is no other option than decoupling it from `AsioSerialPortManager`.

## Dependency Injection (Polymorphic)

The cleanest (IMHO) way to decouple dependencies is to inject their abstractions and use those instead.
If such abstractions do not already exist, this means that you have to define an interface
(i.e. a pure abstract class) that represents the business value the dependencies offer in a rather generic
way. Then, you can have the dependency you need inherit/implement it. Finally, make the constructor of
the class under test receive the interface as an argument.


### [SerialPortAdapter.h](di_polymorphism/serial_port_adapters/public/SerialPortAdapter.h)

The most straight forward way perhaps is to create an abstract interface directly out of the dependency.
However, this is a bad practice since you will be indirectly coupling your code with the particular implementation.
Instead, I suggest you try to figure out what is the business value in a generic manner. With this in mind,
I created the `SerialPortAdapter` interface that generalizes any class that works with the serial port and
exposes a way to transmit data in a generic manner.

```cpp
struct SerialPortAdapter
{
    virtual ~SerialPortAdapter() = default;

    virtual void send(std::string_view message) = 0;
};
```

### AsioSerialPortAdapter [header](di_polymorphism/serial_port_adapters/asio_serial_port_adapter/include/AsioSerialPortAdapter.h) & [implementation](di_polymorphism/serial_port_adapters/asio_serial_port_adapter/src/AsioSerialPortAdapter.cpp)

Then we have the `AsioSerialPortAdapter` concrete class that inherits from `SerialPortAdapter` and exposes
the `AsioSerialPortManager` in a generic manner.

```cpp
class AsioSerialPortAdapter : public SerialPortAdapter
{
public:
    AsioSerialPortAdapter(AsioSerialPortManager* asioSerialPortManager);

    void send(std::string_view message) override;

private:
    AsioSerialPortManager* mAsioSerialPortManager;
};
```

```cpp
AsioSerialPortAdapter::AsioSerialPortAdapter(
    AsioSerialPortManager* asioSerialPortManager)
    : mAsioSerialPortManager{asioSerialPortManager}
{
}

void AsioSerialPortAdapter::send(std::string_view message)
{
    mAsioSerialPortManager->asioWrite(message);
}
```

### [CameraPowerController.h](di_polymorphism/camera_power_controller/include/CameraPowerController.h)

In our `CameraPowerController` we inject the `SerialPortAdapter`. Now, there is nothing specific to the `asio` library.
We are effectively decoupled from it.

```cpp
class CameraPowerController
{
public:
    CameraPowerController(SerialPortAdapter* serialPortAdapter);

    void turnOnCamera();
    void turnOffCamera();

private:
    SerialPortAdapter* mSerialPortAdapter;
};
```

### [di_polymorphism_main.cpp](di_polymorphism/di_polymorphism_main.cpp)

Now that we are injecting things, why not follow the *Inversion of Control* (IoC) principle all the way?
The serial port configuration is probably not a concern of the `CameraPowerController` class, however it takes
place in its constructor. Now that we are injecting resources and letting the users of our classes have control,
we are indirectly encouraged to move these seemingly unrelated functionality outside the class.

```cpp
std::pair<std::filesystem::path, int>
getAsioSerialPortManagerConfiguration(ProductVariant productVariant)
{
    switch (productVariant)
    {
    case ProductVariant::A:
        return std::make_pair(kSerialDevicePathForVariantA,
                              kBaudRateForVariantA);
    case ProductVariant::B:
        return std::make_pair(kSerialDevicePathForVariantB,
                              kBaudRateForVariantB);
    default:
        throw std::logic_error("Unknown variant");
    }
}

int main()
{
    const auto [serialDevice, baudRate]
        = getAsioSerialPortManagerConfiguration(getProductVariant());

    AsioSerialPortManager asioSerialPortManager{serialDevice, baudRate};
    AsioSerialPortAdapter asioSerialPortAdapter{&asioSerialPortManager};
    CameraPowerController cameraPowerController{&asioSerialPortAdapter};
    cameraPowerController.turnOnCamera();
    cameraPowerController.turnOffCamera();

    return 0;
}
```

## Dependency Injection (Templatized)

If many levels of indirection and `virtual` functions are not desirable (e.g. due to strict requirements on performance)
then injecting your dependencies via the constructor is still the way to go. However, this time you will not use a class hierarchy. Instead, you can use a *class template* to determine the type of the constructor argument.

This allows for a looser coupling that is determined by the one that instantiates the class and not the class itself.

### [CameraPowerController.h](di_template/camera_power_controller/include/CameraPowerController.h)

```cpp
template<typename SerialPortManager>
class CameraPowerController
{
public:
    CameraPowerController(SerialPortManager* serialPortManager)
        : mSerialPortManager{serialPortManager}
    {
    }

    void turnOnCamera()
    {
        mSerialPortManager->asioWrite("ON");
    }

    void turnOffCamera()
    {
        mSerialPortManager->asioWrite("OFF");
    }

private:
    SerialPortManager* mSerialPortManager;
};
```
As long as the class template *type* implements an API equivalent to the `AsioSerialPortManager` then our coupling
is only in the design/conceptual level. This is not ideal, however can be good enough for many of the cases. Furthermore,
it should be noted that yet again we have moved the configuration of the serial port outside the class.

## Dependency Injection (Abstract factory)

## Link time switching

## Link time switching (Templatized)
