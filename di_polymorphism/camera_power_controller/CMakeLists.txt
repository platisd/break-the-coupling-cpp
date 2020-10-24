# CameraPowerController
add_library(di_polymorphism_camera_power_controller src/CameraPowerController.cpp)

target_include_directories(di_polymorphism_camera_power_controller PUBLIC include)

target_link_libraries(di_polymorphism_camera_power_controller
        PUBLIC
        serial_port_adapter
        )
