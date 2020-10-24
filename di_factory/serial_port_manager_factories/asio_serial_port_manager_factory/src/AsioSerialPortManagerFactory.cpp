#include "AsioSerialPortManagerFactory.h"
#include "AsioSerialPortManager.h"

std::unique_ptr<SerialPortManager>
AsioSerialPortManagerFactory::get(std::filesystem::path serialDevice,
                                  int baudRate) const
{
    return std::make_unique<AsioSerialPortManager>(serialDevice, baudRate);
}
