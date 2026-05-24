#ifndef TRACKER_H
#define TRACKER_H

#include "../Interfaces/ISubject.h"
#include <vector>
#include <string>

class Tracker : public ISubject {
public:
    void attach(IObserver* observer) override;
    void detach(IObserver* observer) override;
    void notify(const std::string& message) override;
    void updateLocation(int orderId, double progress);

private:
    std::vector<IObserver*> observers;
};

#endif