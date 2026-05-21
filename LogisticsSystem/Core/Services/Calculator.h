#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "../Entities/Order.h"

class Calculator {
public:
    void calculatePrice(Order* order);
};

#endif