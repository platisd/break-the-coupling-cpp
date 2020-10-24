#pragma once

template<typename SerialPortManager>
class CameraPowerController
{
public:
    CameraPowerController(SerialPortManager* serialPortManager)
        : mSerialPortManager{serialPortManager}
    {
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
    SerialPortManager* mSerialPortManager;
};
