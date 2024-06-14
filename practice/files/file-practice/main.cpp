#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::cout << "What city do you live in? ";
    std::string city;
    std::getline(std::cin >> std::ws, city);

    std::ofstream output("../myFile.txt", std::ios::out);

    if (!output) {
        std::cerr << "File could not be opened.\n";
        std::exit(1);
    } else {
        output << "I think you live in Belmopan" << ".\n";
        output.close();
    }

    std::fstream inOut("../myFile.txt", std::ios::in | std::ios::out);
    inOut.seekg(20, std::ios::beg);
    inOut << city;
    inOut.close();

    std::ifstream input("../myFile.txt", std::ios::in);

    if (!input) {
        std::cout << "Error. Could not open file.\n";
        std::exit(1);
    } else {
        std::string word;

        while (input >> word) {
            std::cout << word << ' ';
        }

        input.close();
    }

    return 0;
}
