#include "AsioSerialPortManager.h"

AsioSerialPortManager::AsioSerialPortManager(std::filesystem::path serialDevice,
                                             int baudRate)
{
    mSerialPort.open(serialDevice.c_str());
    mSerialPort.set_option(
        asio::serial_port_base::baud_rate(static_cast<unsigned int>(baudRate)));
}

void AsioSerialPortManager::asioWrite(std::string_view message)
{
    asio::write(mSerialPort, asio::buffer(message));
}
