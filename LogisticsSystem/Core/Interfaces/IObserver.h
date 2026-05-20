#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::string& eventData) = 0;
};

#endif