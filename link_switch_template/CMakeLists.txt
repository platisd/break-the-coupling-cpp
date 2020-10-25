add_subdirectory(camera_power_controller)

# src_main
add_executable(link_switch_template_main link_switch_template_main.cpp)
target_link_libraries(link_switch_template_main
        PRIVATE
        link_switch_template_camera_power_controller
        asio_serial_port_manager
        )
