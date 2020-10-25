add_subdirectory(camera_power_controller)
add_subdirectory(test)

# camera_control_main
add_executable(di_template_main di_template_main.cpp)
target_link_libraries(di_template_main
        PRIVATE
        di_template_camera_power_controller
        asio_serial_port_manager
        asio_serial_port_adapter
        product_variant
        )

