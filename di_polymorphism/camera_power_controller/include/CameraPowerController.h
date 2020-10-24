#pragma once

#include "SerialPortAdapter.h"

class CameraPowerController
{
public:
    CameraPowerController(SerialPortAdapter* serialPortAdapter);

    void turnOnCamera();
    void turnOffCamera();

private:
    SerialPortAdapter* mSerialPortAdapter;
};
