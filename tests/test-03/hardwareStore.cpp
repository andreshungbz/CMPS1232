#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Tool.h"

void readTools(); // EXTRA FOR VERIFICATION
void enterTools();

int main() {
    enterTools();
    readTools();

    return 0;
}

// EXTRA FOR VERIFICATION
void readTools() {
    std::ifstream iFile{"hardware.dat", std::ios::in | std::ios::binary};

    if (!iFile) {
        std::cerr << "hardware.dat could not be read." << std::endl;
        std::exit(1);
    }

    int record{0};
    Tool tool;

    while (true) {
        std::cout << "\nEnter record # to read (Enter -1 to quit): ";
        std::cin >> record;

        if (record < 0) break;

        iFile.seekg((record - 1) * sizeof(Tool), std::ios::beg);
        iFile.read(reinterpret_cast<char*>(&tool), sizeof(Tool));

        std::cout << "Record: " << tool.getRecordSKU() << '\n'
                  << "Name: " << tool.getToolName() << '\n'
                  << "Quantity: " << tool.getQuantity() << '\n';
    }

    iFile.close();
}

void enterTools() {
    std::ofstream oFile{"hardware.dat", std::ios::out | std::ios::binary};

    if (!oFile) {
        std::cerr << "hardware.dat could not be created/opened." << std::endl;
        std::exit(1);
    }

    int record{0};
    std::string toolName;
    int quantity;
    Tool tool;

    while (true) {
        std::cout << "Enter the record # (Press -1 to end program): ";
        std::cin >> record;

        if (record < 0) break;

        std::cout << "Enter the Tool Name: ";
        std::getline(std::cin >> std::ws, toolName);

        std::cout << "Enter the Quantity: ";
        std::cin >> quantity;

        tool.setRecordSKU(record);
        tool.setToolName(toolName);
        tool.setQuantity(quantity);

        oFile.seekp((record - 1) * sizeof(Tool), std::ios::beg);
        oFile.write(reinterpret_cast<const char*>(&tool), sizeof(Tool));

        std::cout << '\n';
    }

    std::cout << "\nData has been saved to hardware.dat\n";

    oFile.close();
}
