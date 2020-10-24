#pragma once

#include <memory>

#include "ProductVariant.h"
#include "SerialPortManager.h"
#include "SerialPortManagerFactory.h"

class CameraPowerController
{
public:
    CameraPowerController(SerialPortManagerFactory* serialPortManagerFactory,
                          ProductVariant productVariant);

    void turnOnCamera();
    void turnOffCamera();

private:
    std::unique_ptr<SerialPortManager> mSerialPortManager;
};
