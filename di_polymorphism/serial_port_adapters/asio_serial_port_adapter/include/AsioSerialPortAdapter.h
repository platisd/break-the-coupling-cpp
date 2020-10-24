#ifndef BREAKTHEDEPENDENCY_ASIOSERIALPORTADATER_H
#define BREAKTHEDEPENDENCY_ASIOSERIALPORTADATER_H

#include "AsioSerialPortManager.h"
#include "SerialPortAdapter.h"

class AsioSerialPortAdapter : public SerialPortAdapter
{
public:
    AsioSerialPortAdapter(AsioSerialPortManager* asioSerialPortManager);

    void send(std::string_view message) override;

private:
    AsioSerialPortManager* mAsioSerialPortManager;
};

#endif // BREAKTHEDEPENDENCY_ASIOSERIALPORTADATER_H
