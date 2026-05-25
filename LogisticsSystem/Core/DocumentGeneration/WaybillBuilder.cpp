#include "WaybillBuilder.h"
#include <sstream>

WaybillBuilder::WaybillBuilder() {
    this->reset();
}

WaybillBuilder::~WaybillBuilder() {
    delete document;
}

void WaybillBuilder::reset() {
    document = new Document();
}

void WaybillBuilder::buildHeader(Order* order) {
    document->header = "=== WAYBILL FOR ORDER #" + std::to_string(order->getId()) + " ===";
}

void WaybillBuilder::buildBody(Order* order) {
    std::ostringstream oss;
    oss << "Cargo Weight: " << order->getWeight() << " kg\n"
        << "Route Distance: " << order->getDistance() << " km\n"
        << "Total Price: $" << order->getPrice() << "\n"
        << "Assigned Driver: " << (order->getDriverName().empty() ? "None" : order->getDriverName()) << "\n"
        << "Current Status: " << order->getStatus();
    document->body = oss.str();
}

void WaybillBuilder::buildFooter() {
    document->footer = "=== END OF WAYBILL ===\n\nDriver Signature: ________________\nClient Signature: ________________";
}

Document* WaybillBuilder::getDocument() {
    Document* result = document;
    document = new Document();
    return result;
}