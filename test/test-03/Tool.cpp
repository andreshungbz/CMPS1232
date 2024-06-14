#include "Tool.h"

Tool::Tool(int newRecord, std::string newToolName, int newQuantity) {
    setRecordSKU(newRecord);
    setToolName(newToolName);
    setQuantity(newQuantity);
}

void Tool::setRecordSKU(int newRecord) {
    recordSKU = newRecord;
}

int Tool::getRecordSKU() const {
    return recordSKU;
}

void Tool::setToolName(const std::string& newToolName) {
    std::size_t length{newToolName.size()};
    length = (length < 50) ? length : 49;
    newToolName.copy(toolName, length);
    toolName[length] = '\0';
}

std::string Tool::getToolName() const {
    return toolName;
}

void Tool::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

int Tool::getQuantity() const {
    return quantity;
}