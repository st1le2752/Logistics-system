#include "OrderHandler.h"

OrderHandler::OrderHandler() {
    calculator = new Calculator();
}

OrderHandler::~OrderHandler() {
    delete calculator;
}

Order* OrderHandler::createOrder(int id, double weight, double distance) {
    Order* order = new Order(id, weight, distance);
    calculator->calculatePrice(order);
    order->setStatus("Priced");
    return order;
}