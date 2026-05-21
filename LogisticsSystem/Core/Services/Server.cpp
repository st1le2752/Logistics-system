#include "Server.h"
#include <sstream>

Server::Server() : nextOrderId(1) {
    orderHandler = new OrderHandler();
}

Server::~Server() {
    delete orderHandler;
}

std::string Server::processNewOrderRequest(double weight, double distance) {
    Order* order = orderHandler->createOrder(nextOrderId++, weight, distance);

    std::ostringstream oss;
    oss << "Order #" << order->getId()
        << " created. Status: " << order->getStatus()
        << " | Price: $" << order->getPrice();

    delete order;
    return oss.str();
}