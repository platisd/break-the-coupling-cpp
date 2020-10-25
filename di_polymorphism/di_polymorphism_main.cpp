#include <utility>

#include "AsioSerialPortAdapter.h"
#include "AsioSerialPortManager.h"
#include "CameraPowerController.h"
#include "ProductVariant.h"

namespace
{
const std::filesystem::path kSerialDevicePathForVariantA{
    "/dev/CoolCompanyDevice"};
const auto kBaudRateForVariantA = 9600;
const std::filesystem::path kSerialDevicePathForVariantB{"COM3"};
const auto kBaudRateForVariantB = 115200;

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

ProductVariant getProductVariant()
{
#if __linux__
    return ProductVariant::A;
#else
    return ProductVariant::B;
#endif
}
} // namespace

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
