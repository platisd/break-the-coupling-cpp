add_subdirectory(libraries/AsioSerialPortManager)
add_subdirectory(libraries/ProductVariant)

add_subdirectory(camera_power_controller)

# src_main
add_executable(src_main main.cpp)
target_link_libraries(src_main
        PRIVATE
        camera_power_controller
        )
