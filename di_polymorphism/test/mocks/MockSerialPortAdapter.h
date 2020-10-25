#ifndef BREAKTHEDEPENDENCY_MOCKSERIALPORTADAPTER_H
#define BREAKTHEDEPENDENCY_MOCKSERIALPORTADAPTER_H

#include "MockSerialPortAdapter.h"
#include <gmock/gmock.h>

class MockSerialPortAdapter : public SerialPortAdapter
{
public:
    MOCK_METHOD(void, send, (std::string_view message), (override));
};

#endif // BREAKTHEDEPENDENCY_MOCKSERIALPORTADAPTER_H
