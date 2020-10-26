#pragma once

#include <memory>

#include "AsioSerialPortManager.h"
#include "ProductVariant.h"

class CameraPowerController
{
public:
    CameraPowerController(ProductVariant productVariant);

    void turnOnCamera();
    void turnOffCamera();

private:
    std::unique_ptr<AsioSerialPortManager> mSerialPortManager;
};
