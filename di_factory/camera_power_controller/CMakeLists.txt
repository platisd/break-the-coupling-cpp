# CameraPowerController
add_library(di_factory_camera_power_controller src/CameraPowerController.cpp)

target_include_directories(di_factory_camera_power_controller PUBLIC include)

target_link_libraries(di_factory_camera_power_controller
        PUBLIC
        serial_port_manager_factory
        product_variant
        )
