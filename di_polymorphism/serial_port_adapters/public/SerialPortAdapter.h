#ifndef BREAKTHEDEPENDENCY_SERIALPORTADATER_H
#define BREAKTHEDEPENDENCY_SERIALPORTADATER_H

#include <string_view>

struct SerialPortAdapter
{
    virtual ~SerialPortAdapter() = default;

    virtual void send(std::string_view message) = 0;
};

#endif // BREAKTHEDEPENDENCY_SERIALPORTADATER_H
