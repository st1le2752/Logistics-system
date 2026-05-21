#include "OrderHandler.h"

OrderHandler::OrderHandler() {
    calculator = new Calculator();
    planner = new Planner();
    coordinator = new Coordinator();
}

OrderHandler::~OrderHandler() {
    delete calculator;
    delete planner;
    delete coordinator;
}

Order* OrderHandler::createOrder(int id, double weight, double distance) {
    Order* order = new Order(id, weight, distance);

    calculator->calculatePrice(order);
    planner->buildRoute(order);
    coordinator->assignDriver(order);

    return order;
}

void OrderHandler::registerDriver(Driver* driver) {
    coordinator->addDriver(driver);
}