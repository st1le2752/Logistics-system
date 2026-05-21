#include "Planner.h"

void Planner::buildRoute(Order* order) {
    if (!order) return;

    order->setStatus("Route Planned");
}