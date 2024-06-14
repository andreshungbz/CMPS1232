#ifndef TOOL_H
#define TOOL_H


#include <string>

class Tool {
public:
    Tool(int newRecord = 0, std::string newToolName = "", int newQuantity = 0);
    void setRecordSKU(int newRecord);
    int getRecordSKU() const;
    void setToolName(const std::string& newToolName);
    std::string getToolName() const;
    void setQuantity(int newQuantity);
    int getQuantity() const;
private:
    int recordSKU;
    char toolName[50];
    int quantity;
};

#endif // TOOL_H