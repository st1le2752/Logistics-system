#ifndef COORDINATOR_H
#define COORDINATOR_H

#include <vector>
#include "../Entities/Driver.h"
#include "../Entities/Order.h"

class Coordinator {
public:
    ~Coordinator();
    void addDriver(Driver* driver);
    bool assignDriver(Order* order);

private:
    std::vector<Driver*> drivers;
};

#endif