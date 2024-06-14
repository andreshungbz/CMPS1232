#include <iostream>
#include <fstream>
#include <cstdlib>

bool isVowel(char c);
void vowelReplacer();

int main() {
    vowelReplacer();

    return 0;
}

bool isVowel(char c) {
    switch (c) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
    }
}

void vowelReplacer() {
    // std::ios::binary is necessary here for Windows text encoding shenanigans
    std::fstream ioFile{"../words.txt", std::ios::in | std::ios::out | std::ios::binary};

    if (!ioFile) {
        std::cerr << "words.txt could not be opened." << std::endl;
        std::exit(1);
    }

    int vowelCount{0};
    int c{ioFile.get()};

    while (!ioFile.eof()) {
        if (isVowel(c)) {
            ioFile.seekp(-1, std::ios::cur);
            ioFile << '#';
            ++vowelCount;
        }

        c = ioFile.get();
    }

    std::cout << "Vowels found and replaced: " << vowelCount << '\n';

    ioFile.close();
}
