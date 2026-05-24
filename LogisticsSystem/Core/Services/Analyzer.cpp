#include "Analyzer.h"
#include <algorithm>
#include <string>

void Analyzer::attach(IObserver* observer) {
    observers.push_back(observer);
}

void Analyzer::detach(IObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Analyzer::notify(const std::string& message) {
    for (IObserver* observer : observers) {
        observer->update(message);
    }
}

void Analyzer::update(const std::string& eventData) {
    if (eventData.find("TRACKER_UPDATE:") != std::string::npos) {
        size_t firstColon = eventData.find(':');
        size_t secondColon = eventData.find(':', firstColon + 1);

        if (firstColon != std::string::npos && secondColon != std::string::npos) {
            std::string orderIdStr = eventData.substr(firstColon + 1, secondColon - firstColon - 1);
            std::string progressStr = eventData.substr(secondColon + 1);

            double progress = std::stod(progressStr);

            if (progress >= 100.0) {
                notify("ALERT: Order " + orderIdStr + " has reached the destination.");
            }
            else if (progress > 0.0) {
                notify("INFO: Order " + orderIdStr + " is en route. Route completed: " + progressStr + "%");
            }
        }
    }
}