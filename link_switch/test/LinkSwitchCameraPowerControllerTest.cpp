#include "CameraPowerController.h"
#include "MockAsioSerialPortManager.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <memory>

namespace
{
const std::filesystem::path kSerialDevicePathForVariantA{
    "/dev/CoolCompanyDevice"};
const auto kBaudRateForVariantA = 9600;
const std::filesystem::path kSerialDevicePathForVariantB{"COM3"};
const auto kBaudRateForVariantB = 115200;
} // namespace

using ::testing::_;
using namespace std::literals;

struct CameraPowerControllerConstructorTest : public ::testing::Test
{
    MockAsioSerialPortManager& mAsioSerialPortManager{
        MockAsioSerialPortManager::getInstance()};
};

TEST_F(CameraPowerControllerConstructorTest,
       constructor_WhenProductVariantA_WillInitializeCorrectSerial)
{
    EXPECT_CALL(mAsioSerialPortManager,
                AsioSerialPortManager(kSerialDevicePathForVariantA,
                                      kBaudRateForVariantA));
    CameraPowerController mCameraPowerController{ProductVariant::A};
}

TEST_F(CameraPowerControllerConstructorTest,
       constructor_WhenProductVariantB_WillInitializeCorrectSerial)
{
    EXPECT_CALL(mAsioSerialPortManager,
                AsioSerialPortManager(kSerialDevicePathForVariantB,
                                      kBaudRateForVariantB));
    CameraPowerController mCameraPowerController{ProductVariant::B};
}

TEST_F(CameraPowerControllerConstructorTest,
       constructor_WhenInvalidProductVariant_WillCrash)
{
    EXPECT_ANY_THROW(CameraPowerController{static_cast<ProductVariant>(23154)});
}

struct CameraPowerControllerTest : public ::testing::Test
{
    void SetUp() override
    {
        // We unfortunately need this expectation here due to calling the
        // singleton mock for the constructor. We can avoid it either by
        // removing the singleton or not setting expectations on the constructor
        EXPECT_CALL(mAsioSerialPortManager, AsioSerialPortManager(_, _));
        mCameraPowerController
            = std::make_unique<CameraPowerController>(ProductVariant::A);
    }

    MockAsioSerialPortManager& mAsioSerialPortManager{
        MockAsioSerialPortManager::getInstance()};
    std::unique_ptr<CameraPowerController> mCameraPowerController;
};

TEST_F(CameraPowerControllerTest,
       turnOnCamera_WhenCalled_WillSendCorrectMessage)
{
    EXPECT_CALL(mAsioSerialPortManager, asioWrite("ON"sv));
    mCameraPowerController->turnOnCamera();
}

TEST_F(CameraPowerControllerTest,
       turnOffCamera_WhenCalled_WillSendCorrectMessage)
{
    EXPECT_CALL(mAsioSerialPortManager, asioWrite("OFF"sv));
    mCameraPowerController->turnOffCamera();
}
