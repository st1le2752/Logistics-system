#include "Server.h"
#include <sstream>

Server::Server() : nextOrderId(1) {
    orderHandler = new OrderHandler();

    orderHandler->registerDriver(new Driver("Ivan (Truck 1)"));
    orderHandler->registerDriver(new Driver("Alex (Truck 2)"));
}

Server::~Server() {
    delete orderHandler;
}

std::string Server::processNewOrderRequest(double weight, double distance) {
    Order* order = orderHandler->createOrder(nextOrderId++, weight, distance);

    std::ostringstream oss;
    oss << "Order #" << order->getId()
        << " | Status: " << order->getStatus()
        << " | Price: $" << order->getPrice()
        << " | Driver: " << (order->getDriverName().empty() ? "NONE" : order->getDriverName());

    delete order;
    return oss.str();
}