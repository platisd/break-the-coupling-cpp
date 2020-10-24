# CameraPowerController
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_library(camera_power_controller src/CameraPowerController.cpp)

target_include_directories(camera_power_controller PUBLIC include)

target_link_libraries(camera_power_controller
        PUBLIC
        asio_serial_port_manager
        product_variant
        Threads::Threads
        )
