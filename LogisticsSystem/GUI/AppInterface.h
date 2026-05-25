#ifndef APPINTERFACE_H
#define APPINTERFACE_H

#include "../Core/Services/Server.h"
#include <string>
#include <vector>

class AppInterface {
public:
    AppInterface();
    ~AppInterface();

    std::string createOrder(double weight, double distance);
    void stepSimulation();
    std::vector<std::string> getSystemMessages();
    std::string getOrderReport(int orderId);

private:
    Server* server;
};

#endif