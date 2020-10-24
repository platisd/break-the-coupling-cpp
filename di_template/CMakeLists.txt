add_subdirectory(camera_power_controller)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# camera_control_main
add_executable(di_template_main di_template_main.cpp)
target_link_libraries(di_template_main
        PRIVATE
        di_template_camera_power_controller
        asio_serial_port_manager
        asio_serial_port_adapter
        product_variant
        Threads::Threads
        )

