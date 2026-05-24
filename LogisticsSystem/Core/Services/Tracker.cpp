#include "Tracker.h"
#include <algorithm>
#include <sstream>

void Tracker::attach(IObserver* observer) {
    observers.push_back(observer);
}

void Tracker::detach(IObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Tracker::notify(const std::string& message) {
    for (IObserver* observer : observers) {
        observer->update(message);
    }
}

void Tracker::updateLocation(int orderId, double progress) {
    std::ostringstream oss;
    oss << "TRACKER_UPDATE:" << orderId << ":" << progress;
    notify(oss.str());
}