#include "Notifier.h"

void Notifier::update(const std::string& eventData) {
    messages.push_back(eventData);
}

std::vector<std::string> Notifier::fetchUnreadMessages() {
    std::vector<std::string> unread = messages;
    messages.clear();
    return unread;
}