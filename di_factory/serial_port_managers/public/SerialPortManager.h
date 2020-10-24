#ifndef BREAKTHEDEPENDENCY_SERIALPORTMANAGER_H
#define BREAKTHEDEPENDENCY_SERIALPORTMANAGER_H

#include <string_view>

struct SerialPortManager
{
    virtual ~SerialPortManager() = default;

    virtual void asioWrite(std::string_view message) = 0;
};

#endif // BREAKTHEDEPENDENCY_SERIALPORTMANAGER_H
