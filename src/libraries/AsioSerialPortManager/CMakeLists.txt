# AsioSerialPortManager

add_library(asio_serial_port_manager_interface INTERFACE)
target_include_directories(asio_serial_port_manager_interface INTERFACE include)
target_link_libraries(asio_serial_port_manager_interface INTERFACE asio)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_library(asio_serial_port_manager src/AsioSerialPortManager.cpp)
target_link_libraries(asio_serial_port_manager
        PUBLIC
        asio_serial_port_manager_interface
        Threads::Threads
        )
