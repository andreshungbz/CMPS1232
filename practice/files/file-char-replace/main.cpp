#include <iostream>
#include <fstream>
#include <cstdlib>

int main() {
    // add std::ios::binary for Windows
    std::ofstream oFile{"../output.txt", std::ios::out};

    if (!oFile) {
        std::cerr << "Output file could not be created.\n";
        std::exit(1);
    }

    oFile << "I think you live in Belmopan.\n";
    oFile << "I think you live in Belmopan.\n";
    oFile << "I think you live in Belmopan.\n";

    oFile.close();

    std::fstream ioFile{"../output.txt", std::ios::in | std::ios::out};

    if (!ioFile) {
        std::cerr << "Output file could not be opened.\n";
        std::exit(1);
    }

    std::cout << "Locations changed:";

    int character{ioFile.get()};
    while (!ioFile.eof()) {
        if (character == 'i' || character == 'I') {
            // move file pointer behind one place to replace
            // both seekp and tellg refer to the same file pointer
            ioFile.seekp(-1, std::ios::cur);
            std::cout << ' ' << ioFile.tellg();
            ioFile << '$';
        }

        character = ioFile.get();
    }

    std::cout << '\n';

    return 0;
}
