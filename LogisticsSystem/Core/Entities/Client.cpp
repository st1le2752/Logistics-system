#include "Client.h"
#include <iostream>

Client::Client(const std::string& name) : name(name) {}

std::string Client::getName() const {
    return name;
}

void Client::receiveNotification(const std::string& message) {
    std::cout << name << " notification: " << message << std::endl;
}