#include "Driver.h"
#include <iostream>

Driver::Driver(const std::string& name) : name(name), available(true) {}

std::string Driver::getName() const {
    return name;
}

void Driver::receiveNotification(const std::string& message) {
    std::cout << name << " notification: " << message << std::endl;
}

void Driver::setAvailable(bool state) {
    available = state;
}

bool Driver::isAvailable() const {
    return available;
}