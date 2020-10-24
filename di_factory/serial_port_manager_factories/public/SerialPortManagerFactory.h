#ifndef BREAKTHEDEPENDENCY_SERIALPORTMANAGERFACTORY_H
#define BREAKTHEDEPENDENCY_SERIALPORTMANAGERFACTORY_H

#include <filesystem>
#include <memory>

#include "SerialPortManager.h"

struct SerialPortManagerFactory
{
    virtual ~SerialPortManagerFactory() = default;

    virtual std::unique_ptr<SerialPortManager>
    get(std::filesystem::path serialDevice, int baudRate) const = 0;
};

#endif // BREAKTHEDEPENDENCY_SERIALPORTMANAGERFACTORY_H
