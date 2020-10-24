#ifndef BREAKTHEDEPENDENCY_CAMERAPOWERCONTROLLER_H
#define BREAKTHEDEPENDENCY_CAMERAPOWERCONTROLLER_H

#include <memory>

#include "AsioSerialPortManager.h"
#include "ProductVariant.h"

class CameraPowerController
{
public:
    CameraPowerController(ProductVariant productVariant);

    void turnOnCamera();
    void turnOffCamera();

private:
    std::unique_ptr<AsioSerialPortManager> mSerialPortManager;
};
#endif // BREAKTHEDEPENDENCY_CAMERAPOWERCONTROLLER_H
