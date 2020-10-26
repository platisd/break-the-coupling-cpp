add_subdirectory(camera_power_controller)
add_subdirectory(test)

# src_main
add_executable(link_switch_main link_switch_main.cpp)
target_link_libraries(link_switch_main
        PRIVATE
        link_switch_camera_power_controller
        asio_serial_port_manager
        )
