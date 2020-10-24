# SerialPortAdapter interface
add_library(serial_port_adapter INTERFACE)
target_include_directories(serial_port_adapter INTERFACE public)

# AsioSerialPortAdapter
add_library(asio_serial_port_adapter asio_serial_port_adapter/src/AsioSerialPortAdapter.cpp)
target_include_directories(asio_serial_port_adapter PUBLIC asio_serial_port_adapter/include)
target_link_libraries(asio_serial_port_adapter
        PUBLIC
        serial_port_adapter
        asio_serial_port_manager)
