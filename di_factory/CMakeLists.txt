add_subdirectory(camera_power_controller)
add_subdirectory(serial_port_manager_factories)
add_subdirectory(serial_port_managers)
add_subdirectory(test)

# di_factory_main
add_executable(di_factory_main di_factory_main.cpp)
target_link_libraries(di_factory_main
        PRIVATE
        di_factory_camera_power_controller
        asio_serial_port_manager_factory
        )
