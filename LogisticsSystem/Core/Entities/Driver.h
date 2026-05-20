#ifndef DRIVER_H
#define DRIVER_H

#include "../Interfaces/IUser.h"
#include <string>

class Driver : public IUser {
public:
    explicit Driver(const std::string& name);

    std::string getName() const override;
    void receiveNotification(const std::string& message) override;
    void setAvailable(bool state);
    bool isAvailable() const;

private:
    std::string name;
    bool available;
};

#endif