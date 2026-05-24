#include "Server.h"
#include <sstream>

Server::Server() : nextOrderId(1), currentProgressStep(0.0) {
    orderHandler = new OrderHandler();
    tracker = new Tracker();
    analyzer = new Analyzer();
    notifier = new Notifier();

    tracker->attach(analyzer);
    analyzer->attach(notifier);

    orderHandler->registerDriver(new Driver("Ivan (Truck 1)"));
    orderHandler->registerDriver(new Driver("Alex (Truck 2)"));
}

Server::~Server() {
    delete orderHandler;
    delete tracker;
    delete analyzer;
    delete notifier;
    for (Order* order : activeOrders) {
        delete order;
    }
}

std::string Server::processNewOrderRequest(double weight, double distance) {
    Order* order = orderHandler->createOrder(nextOrderId++, weight, distance);

    activeOrders.push_back(order);

    std::ostringstream oss;
    oss << "Order #" << order->getId()
        << " | Status: " << order->getStatus()
        << " | Price: $" << order->getPrice()
        << " | Driver: " << (order->getDriverName().empty() ? "NONE" : order->getDriverName());

    return oss.str();
}

void Server::simulateSimulationStep() {
    currentProgressStep += 25.0;
    if (currentProgressStep > 100.0) {
        currentProgressStep = 100.0;
    }

    for (Order* order : activeOrders) {
        if (!order->getDriverName().empty() && order->getStatus() != "Delivered") {
            tracker->updateLocation(order->getId(), currentProgressStep);
            if (currentProgressStep >= 100.0) {
                order->setStatus("Delivered");
            }
        }
    }
}

std::vector<std::string> Server::getNotifications() {
    return notifier->fetchUnreadMessages();
}