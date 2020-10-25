#pragma once

#include <memory>

#include "AsioSerialPortManager.h"
#include "ProductVariant.h"

template<typename SerialPortManager>
class CameraPowerController
{
public:
    CameraPowerController(ProductVariant productVariant)
    {
        switch (productVariant)
        {
        case ProductVariant::A:
        {
            const std::filesystem::path kSerialDevicePathForVariantA{
                "/dev/CoolCompanyDevice"};
            const auto kBaudRateForVariantA = 9600;
            mSerialPortManager = std::make_unique<AsioSerialPortManager>(
                kSerialDevicePathForVariantA, kBaudRateForVariantA);
        }
            return;
        case ProductVariant::B:
        {
            const std::filesystem::path kSerialDevicePathForVariantB{"COM3"};
            const auto kBaudRateForVariantB = 115200;
            mSerialPortManager = std::make_unique<AsioSerialPortManager>(
                kSerialDevicePathForVariantB, kBaudRateForVariantB);
        }
            return;
        default:
            throw std::logic_error("Unknown variant");
        }
    }

    void turnOnCamera()
    {
        mSerialPortManager->asioWrite("ON");
    }

    void turnOffCamera()
    {
        mSerialPortManager->asioWrite("OFF");
    }

private:
    std::unique_ptr<SerialPortManager> mSerialPortManager;
};
