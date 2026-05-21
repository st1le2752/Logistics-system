#ifndef ORDERHANDLER_H
#define ORDERHANDLER_H

#include "../Entities/Order.h"
#include "../Entities/Driver.h"
#include "Calculator.h"
#include "Planner.h"
#include "Coordinator.h"

class OrderHandler {
public:
    OrderHandler();
    ~OrderHandler();
    Order* createOrder(int id, double weight, double distance);
    void registerDriver(Driver* driver);

private:
    Calculator* calculator;
    Planner* planner;
    Coordinator* coordinator;
};

#endif