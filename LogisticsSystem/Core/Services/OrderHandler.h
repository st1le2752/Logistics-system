#ifndef ORDERHANDLER_H
#define ORDERHANDLER_H

#include "../Entities/Order.h"
#include "Calculator.h"

class OrderHandler {
public:
    OrderHandler();
    ~OrderHandler();
    Order* createOrder(int id, double weight, double distance);

private:
    Calculator* calculator;
};

#endif