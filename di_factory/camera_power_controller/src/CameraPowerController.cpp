#include <stdexcept>

#include "CameraPowerController.h"

namespace
{
std::filesystem::path kSerialDevicePathForVariantA{"/dev/CoolCompanyDevice"};
const auto kBaudRateForVariantA = 9600;
std::filesystem::path kSerialDevicePathForVariantB{"COM3"};
const auto kBaudRateForVariantB = 115200;
} // namespace

CameraPowerController::CameraPowerController(
    SerialPortManagerFactory* serialPortManagerFactory,
    ProductVariant productVariant)
{
    switch (productVariant)
    {
    case ProductVariant::A:
        mSerialPortManager = serialPortManagerFactory->get(
            kSerialDevicePathForVariantA, kBaudRateForVariantA);
        return;
    case ProductVariant::B:
        mSerialPortManager = serialPortManagerFactory->get(
            kSerialDevicePathForVariantB, kBaudRateForVariantB);
        return;
    default:
        throw std::logic_error("Unknown variant");
    }
}

void CameraPowerController::turnOnCamera()
{
    mSerialPortManager->asioWrite("ON");
}

void CameraPowerController::turnOffCamera()
{
    mSerialPortManager->asioWrite("OFF");
}
