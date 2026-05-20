#ifndef IUSER_H
#define IUSER_H

#include <string>

class IUser {
public:
    virtual ~IUser() = default;
    virtual std::string getName() const = 0;
    virtual void receiveNotification(const std::string& message) = 0;
};

#endif