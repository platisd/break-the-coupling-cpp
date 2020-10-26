# CameraPowerController
add_library(link_switch_camera_power_controller src/CameraPowerController.cpp)

target_include_directories(link_switch_camera_power_controller PUBLIC include)

target_link_libraries(link_switch_camera_power_controller
        PUBLIC
        asio_serial_port_manager_interface
        product_variant
        )
