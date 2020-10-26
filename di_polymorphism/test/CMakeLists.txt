set(mocks ${CMAKE_CURRENT_SOURCE_DIR}/mocks)

# DiPolymorphismCameraPowerControllerTest
add_executable(di_polymorphism_camera_power_controller_test DiPolymorphismCameraPowerControllerTest.cpp)
target_include_directories(di_polymorphism_camera_power_controller_test PUBLIC
        ${mocks})
target_link_libraries(di_polymorphism_camera_power_controller_test
        di_polymorphism_camera_power_controller
        product_variant)
configure_test(di_polymorphism_camera_power_controller_test)
