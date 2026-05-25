#ifndef WAYBILLBUILDER_H
#define WAYBILLBUILDER_H

#include "../Interfaces/IDocBuilder.h"

class WaybillBuilder : public IDocBuilder {
public:
    WaybillBuilder();
    ~WaybillBuilder();

    void reset() override;
    void buildHeader(Order* order) override;
    void buildBody(Order* order) override;
    void buildFooter() override;
    Document* getDocument() override;

private:
    Document* document;
};

#endif