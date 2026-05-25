#ifndef GENERATOR_H
#define GENERATOR_H

#include "../Interfaces/IDocBuilder.h"
#include "../Entities/Order.h"

class Generator {
public:
    Document* createDocument(IDocBuilder* builder, Order* order);
};

#endif