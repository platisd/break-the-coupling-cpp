add_subdirectory(camera_power_controller)
add_subdirectory(serial_port_adapters)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# camera_control_main
add_executable(di_polymorphism_main di_polymorphism_main.cpp)
target_link_libraries(di_polymorphism_main
        PRIVATE
        di_polymorphism_camera_power_controller
        asio_serial_port_manager
        asio_serial_port_adapter
        product_variant
        Threads::Threads
        )

