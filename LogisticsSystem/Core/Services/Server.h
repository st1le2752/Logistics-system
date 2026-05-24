#ifndef SERVER_H
#define SERVER_H

#include "OrderHandler.h"
#include "Tracker.h"
#include "Analyzer.h"
#include "Notifier.h"
#include <string>
#include <vector>

class Server {
public:
    Server();
    ~Server();
    std::string processNewOrderRequest(double weight, double distance);
    void simulateSimulationStep();
    std::vector<std::string> getNotifications();

private:
    OrderHandler* orderHandler;
    Tracker* tracker;
    Analyzer* analyzer;
    Notifier* notifier;
    std::vector<Order*> activeOrders;
    int nextOrderId;
    double currentProgressStep;
};

#endif