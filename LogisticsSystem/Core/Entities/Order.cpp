#include "Order.h"

Order::Order(int id, double weight, double distance)
    : id(id), weight(weight), distance(distance), price(0.0), status("Created") {
}

int Order::getId() const { return id; }
double Order::getWeight() const { return weight; }
double Order::getDistance() const { return distance; }
double Order::getPrice() const { return price; }
std::string Order::getStatus() const { return status; }

void Order::setPrice(double newPrice) { price = newPrice; }
void Order::setStatus(const std::string& newStatus) { status = newStatus; }