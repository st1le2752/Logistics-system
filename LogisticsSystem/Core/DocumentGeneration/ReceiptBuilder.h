#ifndef RECEIPTBUILDER_H
#define RECEIPTBUILDER_H

#include "../Interfaces/IDocBuilder.h"

class ReceiptBuilder : public IDocBuilder {
public:
    ReceiptBuilder();
    ~ReceiptBuilder();

    void reset() override;
    void buildHeader(Order* order) override;
    void buildBody(Order* order) override;
    void buildFooter() override;
    Document* getDocument() override;

private:
    Document* document;
};

#endif