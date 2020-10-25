#ifndef BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGER_H
#define BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGER_H

#include "SerialPortManager.h"
#include <gmock/gmock.h>

class MockSerialPortManager : public SerialPortManager
{
public:
    MOCK_METHOD1(asioWrite, void(std::string_view message));
};

#endif // BREAKTHEDEPENDENCY_MOCKSERIALPORTMANAGER_H
