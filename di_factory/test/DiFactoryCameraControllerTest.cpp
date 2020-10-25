#include "CameraPowerController.h"
#include "MockSerialPortManager.h"
#include "MockSerialPortManagerFactory.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <memory>

using namespace std::literals;
using ::testing::_;
using ::testing::ByMove;
using ::testing::Return;

namespace
{
const std::filesystem::path kSerialDevicePathForVariantA{
    "/dev/CoolCompanyDevice"};
const auto kBaudRateForVariantA = 9600;
const std::filesystem::path kSerialDevicePathForVariantB{"COM3"};
const auto kBaudRateForVariantB = 115200;
} // namespace

struct CameraPowerControllerConstructorTest : public ::testing::Test
{
    MockSerialPortManagerFactory mSerialPortManagerFactory;
};

TEST_F(CameraPowerControllerConstructorTest,
       constructor_WhenProductVariantA_WillCreateCorrectSerialPortManager)
{
    EXPECT_CALL(mSerialPortManagerFactory,
                get(kSerialDevicePathForVariantA, kBaudRateForVariantA));

    CameraPowerController cameraPowerController{&mSerialPortManagerFactory,
                                                ProductVariant::A};
}

TEST_F(CameraPowerControllerConstructorTest,
       constructor_WhenProductVariantB_WillCreateCorrectSerialPortManager)
{
    EXPECT_CALL(mSerialPortManagerFactory,
                get(kSerialDevicePathForVariantB, kBaudRateForVariantB));

    CameraPowerController cameraPowerController{&mSerialPortManagerFactory,
                                                ProductVariant::B};
}

TEST_F(CameraPowerControllerConstructorTest,
       constructor_WhenInvalidProductVariant_WillCrash)
{
    EXPECT_ANY_THROW(CameraPowerController(&mSerialPortManagerFactory,
                                           static_cast<ProductVariant>(51323)));
}

struct CameraPowerControllerTest : public ::testing::Test
{
    void SetUp() override
    {
        auto serialPortManagerToReturn
            = std::make_unique<MockSerialPortManager>();
        mSerialPortManager = serialPortManagerToReturn.get();

        EXPECT_CALL(mSerialPortManagerFactory, get(_, _))
            .WillOnce(Return(ByMove(std::move(serialPortManagerToReturn))));

        mCameraPowerController = std::make_unique<CameraPowerController>(
            &mSerialPortManagerFactory, ProductVariant::A);
    }

    MockSerialPortManagerFactory mSerialPortManagerFactory;
    MockSerialPortManager* mSerialPortManager;
    std::unique_ptr<CameraPowerController> mCameraPowerController;
};

TEST_F(CameraPowerControllerTest, turnOnCamera_WhenCalled_WillSendTurnOnCommand)
{
    EXPECT_CALL(*mSerialPortManager, asioWrite("ON"sv));
    mCameraPowerController->turnOnCamera();
}

TEST_F(CameraPowerControllerTest,
       turnOffCamera_WhenCalled_WillSendTurnOffCommand)
{
    EXPECT_CALL(*mSerialPortManager, asioWrite("OFF"sv));
    mCameraPowerController->turnOffCamera();
}
