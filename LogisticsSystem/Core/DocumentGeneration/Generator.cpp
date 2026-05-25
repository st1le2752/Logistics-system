#include "Generator.h"

Document* Generator::createDocument(IDocBuilder* builder, Order* order) {
    if (!builder || !order) return nullptr;

    builder->reset();
    builder->buildHeader(order);
    builder->buildBody(order);
    builder->buildFooter();

    return builder->getDocument();
}