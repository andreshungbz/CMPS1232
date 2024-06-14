#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream inputFile{"../input.txt", std::ios::in};

    if (!inputFile) {
        std::cerr << "Input file could not be opened for reading.";
        std::exit(EXIT_FAILURE);
    }

    std::ofstream outputFile{"../output.txt", std::ios::out};

    if (!outputFile) {
        std::cerr << "Output file could not be opened for writing.";
        std::exit(EXIT_FAILURE);
    }

    std::string input;
    std::getline(inputFile, input);

    while (!inputFile.eof()) {
        int grade{std::stoi(input)};

        if (grade >= 70) {
            outputFile << grade << '\n';
        }

        std::getline(inputFile, input);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Grades >= 70 have been written to output.txt.\n";

    return 0;
}
