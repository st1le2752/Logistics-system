#ifndef PLANNER_H
#define PLANNER_H

#include "../Entities/Order.h"

class Planner {
public:
    void buildRoute(Order* order);
};

#endif