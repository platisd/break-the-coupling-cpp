#include "CameraPowerController.h"

CameraPowerController::CameraPowerController(
    SerialPortAdapter* serialPortAdapter)
    : mSerialPortAdapter{serialPortAdapter}
{
}

void CameraPowerController::turnOnCamera()
{
    mSerialPortAdapter->send("ON");
}

void CameraPowerController::turnOffCamera()
{
    mSerialPortAdapter->send("OFF");
}
