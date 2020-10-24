# AsioSerialPortManager

add_library(asio_serial_port_manager_interface INTERFACE)
target_include_directories(asio_serial_port_manager_interface INTERFACE include)

add_library(asio_serial_port_manager src/AsioSerialPortManager.cpp)
target_link_libraries(asio_serial_port_manager
        PUBLIC
        asio_serial_port_manager_interface
        asio
        )
