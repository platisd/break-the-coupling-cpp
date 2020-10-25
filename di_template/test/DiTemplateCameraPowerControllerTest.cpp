#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "CameraPowerController.h"

using namespace std::literals;

class MockAsioSerialPortManager /* Nothing to inherit! */
{
public:
    MOCK_METHOD(void, asioWrite, (std::string_view message), ());
};

struct CameraPowerControllerTest : public ::testing::Test
{
    MockAsioSerialPortManager mAsioSerialPortManager;
    CameraPowerController<MockAsioSerialPortManager> mCameraPowerController{
        &mAsioSerialPortManager};
};

TEST_F(CameraPowerControllerTest,
       turnOnCamera_WhenCalled_WillSendCorrectMessage)
{
    EXPECT_CALL(mAsioSerialPortManager, asioWrite("ON"sv));
    mCameraPowerController.turnOnCamera();
}

TEST_F(CameraPowerControllerTest,
       turnOffCamera_WhenCalled_WillSendCorrectMessage)
{
    EXPECT_CALL(mAsioSerialPortManager, asioWrite("OFF"sv));
    mCameraPowerController.turnOffCamera();
}
