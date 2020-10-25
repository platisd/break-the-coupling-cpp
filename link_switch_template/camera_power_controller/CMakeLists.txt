# CameraPowerController
add_library(link_switch_template_camera_power_controller INTERFACE)

target_include_directories(link_switch_template_camera_power_controller INTERFACE include)

target_link_libraries(link_switch_template_camera_power_controller
        INTERFACE
        asio_serial_port_manager_interface
        product_variant
        )
