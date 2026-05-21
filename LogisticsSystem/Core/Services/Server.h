#ifndef SERVER_H
#define SERVER_H

#include "OrderHandler.h"
#include <string>

class Server {
public:
    Server();
    ~Server();
    std::string processNewOrderRequest(double weight, double distance);

private:
    OrderHandler* orderHandler;
    int nextOrderId;
};

#endif