#ifndef BREAKTHEDEPENDENCY_ASIOSERIALPORTMANAGER_H
#define BREAKTHEDEPENDENCY_ASIOSERIALPORTMANAGER_H

#include <filesystem>
#include <string_view>

#include <asio.hpp>

class AsioSerialPortManager
{
public:
    AsioSerialPortManager(std::filesystem::path serialDevice, int baudRate);

    void asioWrite(std::string_view message);

private:
    asio::io_service mIoService;
    asio::serial_port mSerialPort{mIoService};
};

#endif // BREAKTHEDEPENDENCY_ASIOSERIALPORTMANAGER_H
