#include "Coordinator.h"

Coordinator::~Coordinator() {
    for (Driver* driver : drivers) {
        delete driver;
    }
    drivers.clear();
}

void Coordinator::addDriver(Driver* driver) {
    drivers.push_back(driver);
}

bool Coordinator::assignDriver(Order* order) {
    if (!order) return false;

    for (Driver* driver : drivers) {
        if (driver->isAvailable()) {
            driver->setAvailable(false);
            order->setDriverName(driver->getName());
            order->setStatus("Driver Assigned");
            return true;
        }
    }

    order->setStatus("Pending: No Drivers");
    return false;
}