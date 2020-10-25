# ========= Unit test configurations =========
set(mocks ${CMAKE_CURRENT_SOURCE_DIR}/mocks)

# DiFactoryCameraControllerTest
add_executable(di_factory_camera_power_controller_test DiFactoryCameraPowerControllerTest.cpp)
target_include_directories(di_factory_camera_power_controller_test PUBLIC
        ${mocks})
target_link_libraries(di_factory_camera_power_controller_test
        di_factory_camera_power_controller)
configure_test(di_factory_camera_power_controller_test)
