#ifndef BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGER_H
#define BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGER_H

#include "SerialPortManager.h"
#include <gmock/gmock.h>

class MockSerialPortManager : public SerialPortManager
{
public:
    MOCK_METHOD(void, asioWrite, (std::string_view message), (override));
};

#endif // BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGER_H
