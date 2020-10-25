#ifndef BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGERFACTORY_H
#define BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGERFACTORY_H

#include <gmock/gmock.h>

#include "MockSerialPortManagerFactory.h"

class MockSerialPortManagerFactory : public SerialPortManagerFactory
{
public:
    MOCK_METHOD(std::unique_ptr<SerialPortManager>,
                get,
                (std::filesystem::path serialDevice, int baudRate),
                (const, override));
};

#endif // BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGERFACTORY_H
