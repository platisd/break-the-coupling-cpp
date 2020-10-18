add_subdirectory(AsioSerialPortManager)
add_subdirectory(ProductVariant)

# AsioSerialPortManager
add_library(asio_serial_port_manager ${asio_serial_port_manager_sources})
target_include_directories(asio_serial_port_manager PUBLIC ${asio_serial_port_manager_header_dir})
target_link_libraries(asio_serial_port_manager
        PUBLIC
        asio
        )

# CameraPowerController
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
add_library(camera_power_controller CameraPowerController/src/CameraPowerController.cpp)
target_include_directories(camera_power_controller PUBLIC CameraPowerController/include)
target_link_libraries(camera_power_controller
        PUBLIC
        asio_serial_port_manager
        product_variant
        Threads::Threads
        )


# camera_control_main
add_executable(camera_control_main camera_control_main.cpp)
target_link_libraries(camera_control_main
        PRIVATE
        camera_power_controller
        )

