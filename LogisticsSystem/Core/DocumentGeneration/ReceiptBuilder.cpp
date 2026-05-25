#include "ReceiptBuilder.h"
#include <sstream>

ReceiptBuilder::ReceiptBuilder() {
    this->reset();
}

ReceiptBuilder::~ReceiptBuilder() {
    delete document;
}

void ReceiptBuilder::reset() {
    document = new Document();
}

void ReceiptBuilder::buildHeader(Order* order) {
    document->header = "--- PAYMENT RECEIPT FOR ORDER #" + std::to_string(order->getId()) + " ---";
}

void ReceiptBuilder::buildBody(Order* order) {
    std::ostringstream oss;
    oss << "Service: Cargo Transportation\n"
        << "Total Amount Paid: $" << order->getPrice() << "\n"
        << "Status: PAID IN FULL";
    document->body = oss.str();
}

void ReceiptBuilder::buildFooter() {
    document->footer = "Thank you for choosing our logistics service!\nDate: 2024-05-20";
}

Document* ReceiptBuilder::getDocument() {
    Document* result = document;
    document = new Document();
    return result;
}