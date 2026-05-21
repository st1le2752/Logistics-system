#ifndef ORDER_H
#define ORDER_H

#include <string>

class Order {
public:
    Order(int id, double weight, double distance);

    int getId() const;
    double getWeight() const;
    double getDistance() const;
    double getPrice() const;
    std::string getStatus() const;
    std::string getDriverName() const;

    void setPrice(double newPrice);
    void setStatus(const std::string& newStatus);
    void setDriverName(const std::string& name);

private:
    int id;
    double weight;
    double distance;
    double price;
    std::string status;
    std::string driverName;
};

#endif