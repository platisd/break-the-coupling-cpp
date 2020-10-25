#ifndef BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGERFACTORY_H
#define BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGERFACTORY_H

#include <gmock/gmock.h>

#include "MockSerialPortManagerFactory.h"

class MockSerialPortManagerFactory : public SerialPortManagerFactory
{
public:
    MOCK_CONST_METHOD2(get,
                       std::unique_ptr<SerialPortManager>(
                           std::filesystem::path serialDevice, int baudRate));
};

#endif // BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGERFACTORY_H
