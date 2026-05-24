#ifndef NOTIFIER_H
#define NOTIFIER_H

#include "../Interfaces/IObserver.h"
#include <vector>
#include <string>

class Notifier : public IObserver {
public:
    void update(const std::string& eventData) override;
    std::vector<std::string> fetchUnreadMessages();

private:
    std::vector<std::string> messages;
};

#endif