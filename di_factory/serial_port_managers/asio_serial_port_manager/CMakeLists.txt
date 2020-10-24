# AsioSerialPortManager

add_library(virtual_asio_serial_port_manager_interface INTERFACE)
target_include_directories(virtual_asio_serial_port_manager_interface INTERFACE include)
target_link_libraries(virtual_asio_serial_port_manager_interface INTERFACE serial_port_manager)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_library(virtual_asio_serial_port_manager src/AsioSerialPortManager.cpp)
target_link_libraries(virtual_asio_serial_port_manager
        PUBLIC
        virtual_asio_serial_port_manager_interface
        asio
        Threads::Threads
        )
