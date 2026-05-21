#include "Calculator.h"

void Calculator::calculatePrice(Order* order) {
    if (!order) return;
    double baseRate = 1.5;
    double price = order->getDistance() * baseRate + order->getWeight() * 2.0;
    order->setPrice(price);
}