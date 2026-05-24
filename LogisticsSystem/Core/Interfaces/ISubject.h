#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "IObserver.h"
#include <string>

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notify(const std::string& message) = 0;
};

#endif