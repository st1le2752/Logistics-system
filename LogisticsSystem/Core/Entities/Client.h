#ifndef CLIENT_H
#define CLIENT_H

#include "../Interfaces/IUser.h"
#include <string>

class Client : public IUser {
public:
    explicit Client(const std::string& name);

    std::string getName() const override;
    void receiveNotification(const std::string& message) override;

private:
    std::string name;
};

#endif