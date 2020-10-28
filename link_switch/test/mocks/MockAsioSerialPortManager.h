#ifndef BREAKTHEDEPENDENCY_MOCKASIOSERIALPORTMANAGER_H
#define BREAKTHEDEPENDENCY_MOCKASIOSERIALPORTMANAGER_H

#include "gmock/gmock.h"
#include <filesystem>
#include <string_view>

struct MockAsioSerialPortManager
{
    MOCK_METHOD(void, asioWrite, (std::string_view message), ());
    MOCK_METHOD(void,
                AsioSerialPortManager,
                (std::filesystem::path serialDevice, int baudRate),
                ());

    static MockAsioSerialPortManager& getInstance()
    {
        static MockAsioSerialPortManager instance;

        return instance;
    }

private:
    MockAsioSerialPortManager() = default;
};

#endif // BREAKTHEDEPENDENCY_MOCKASIOSERIALPORTMANAGER_H
