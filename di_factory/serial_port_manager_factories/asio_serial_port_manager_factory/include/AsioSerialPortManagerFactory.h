#ifndef BREAKTHEDEPENDENCY_ASIOSERIALPORTMANAGERFACTORY_H
#define BREAKTHEDEPENDENCY_ASIOSERIALPORTMANAGERFACTORY_H

#include "SerialPortManagerFactory.h"

class AsioSerialPortManagerFactory : public SerialPortManagerFactory
{
public:
    std::unique_ptr<SerialPortManager> get(std::filesystem::path serialDevice,
                                           int baudRate) const override;
};

#endif // BREAKTHEDEPENDENCY_ASIOSERIALPORTMANAGERFACTORY_H
