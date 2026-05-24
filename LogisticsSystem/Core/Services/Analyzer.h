#ifndef ANALYZER_H
#define ANALYZER_H

#include "../Interfaces/IObserver.h"
#include "../Interfaces/ISubject.h"
#include <vector>
#include <string>

class Analyzer : public IObserver, public ISubject {
public:
    void update(const std::string& eventData) override;
    void attach(IObserver* observer) override;
    void detach(IObserver* observer) override;
    void notify(const std::string& message) override;

private:
    std::vector<IObserver*> observers;
};

#endif