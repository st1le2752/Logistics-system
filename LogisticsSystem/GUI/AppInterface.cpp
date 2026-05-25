#include "AppInterface.h"

AppInterface::AppInterface() {
    server = new Server();
}

AppInterface::~AppInterface() {
    delete server;
}

std::string AppInterface::createOrder(double weight, double distance) {
    return server->processNewOrderRequest(weight, distance);
}

void AppInterface::stepSimulation() {
    server->simulateSimulationStep();
}

std::vector<std::string> AppInterface::getSystemMessages() {
    return server->getNotifications();
}

std::string AppInterface::getOrderReport(int orderId) {
    return server->generateOrderDocument(orderId);
}