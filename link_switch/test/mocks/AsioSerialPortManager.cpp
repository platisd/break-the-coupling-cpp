#include "AsioSerialPortManager.h"
#include "MockAsioSerialPortManager.h"

AsioSerialPortManager::AsioSerialPortManager(std::filesystem::path serialDevice,
                                             int baudRate)
{
    MockAsioSerialPortManager::getInstance().AsioSerialPortManager(serialDevice,
                                                                   baudRate);
}

void AsioSerialPortManager::asioWrite(std::string_view message)
{
    MockAsioSerialPortManager::getInstance().asioWrite(message);
}
