#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "CameraPowerController.h"
#include "MockSerialPortAdapter.h"

using namespace std::literals;

struct CameraPowerControllerTest : public ::testing::Test
{
    MockSerialPortAdapter mSerialPortAdapter;
    CameraPowerController mCameraPowerController{&mSerialPortAdapter};
};

TEST_F(CameraPowerControllerTest,
       turnOnCamera_WhenCalled_WillSendCorrectMessage)
{
    EXPECT_CALL(mSerialPortAdapter, send("ON"sv));
    mCameraPowerController.turnOnCamera();
}

TEST_F(CameraPowerControllerTest,
       turnOffCamera_WhenCalled_WillSendCorrectMessage)
{
    EXPECT_CALL(mSerialPortAdapter, send("OFF"sv));
    mCameraPowerController.turnOffCamera();
}
