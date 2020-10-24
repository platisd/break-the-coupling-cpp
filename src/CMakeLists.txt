add_subdirectory(libraries/AsioSerialPortManager)
add_subdirectory(libraries/ProductVariant)

add_subdirectory(camera_power_controller)

# camera_control_main
add_executable(camera_control_main camera_control_main.cpp)
target_link_libraries(camera_control_main
        PRIVATE
        camera_power_controller
        )

