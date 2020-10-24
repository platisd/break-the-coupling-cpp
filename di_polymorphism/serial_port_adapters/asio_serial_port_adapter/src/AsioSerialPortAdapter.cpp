#include "AsioSerialPortAdapter.h"

AsioSerialPortAdapter::AsioSerialPortAdapter(
    AsioSerialPortManager* asioSerialPortManager)
    : mAsioSerialPortManager{asioSerialPortManager}
{
}

void AsioSerialPortAdapter::send(std::string_view message)
{
    mAsioSerialPortManager->asioWrite(message);
}
