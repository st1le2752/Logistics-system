#ifndef IDOCBUILDER_H
#define IDOCBUILDER_H

#include "../DocumentGeneration/Document.h"
#include "../Entities/Order.h"

class IDocBuilder {
public:
    virtual ~IDocBuilder() = default;
    virtual void reset() = 0;
    virtual void buildHeader(Order* order) = 0;
    virtual void buildBody(Order* order) = 0;
    virtual void buildFooter() = 0;
    virtual Document* getDocument() = 0;
};

#endif