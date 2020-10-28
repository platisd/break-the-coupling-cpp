#include <stdexcept>

#include "CameraPowerController.h"

namespace
{
const std::filesystem::path kSerialDevicePathForVariantA{
    "/dev/CoolCompanyDevice"};
const auto kBaudRateForVariantA = 9600;
const std::filesystem::path kSerialDevicePathForVariantB{"COM3"};
const auto kBaudRateForVariantB = 115200;
} // namespace

CameraPowerController::CameraPowerController(ProductVariant productVariant)
{
    switch (productVariant)
    {
    case ProductVariant::A:
        mAsioSerialPortManager = std::make_unique<AsioSerialPortManager>(
            kSerialDevicePathForVariantA, kBaudRateForVariantA);
        return;
    case ProductVariant::B:
        mAsioSerialPortManager = std::make_unique<AsioSerialPortManager>(
            kSerialDevicePathForVariantB, kBaudRateForVariantB);
        return;
    default:
        throw std::logic_error("Unknown variant");
    }
}

void CameraPowerController::turnOnCamera()
{
    mAsioSerialPortManager->asioWrite("ON");
}

void CameraPowerController::turnOffCamera()
{
    mAsioSerialPortManager->asioWrite("OFF");
}
