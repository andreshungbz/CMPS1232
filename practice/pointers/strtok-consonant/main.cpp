#include <cstring>
#include <iomanip>
#include <iostream>

bool isConsonant(char letter);
void consonantReplace(char* word);

int main() {
    char sentence[] {"This is a sentence with 7 tokens"};
    std::cout << "Sentence: " << sentence << "\nTokens:\n";

    char* tokenPtr{std::strtok(sentence, " ")};

    while (tokenPtr != nullptr) {
        std::cout << tokenPtr << std::setw(10);
        consonantReplace(tokenPtr);
        std::cout << tokenPtr << '\n';
        tokenPtr = std::strtok(nullptr, " ");
    }

    return 0;
}

bool isConsonant(const char letter) {
    static char consonants[21] {
            'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'
    };

    for (std::size_t i{0}; i < 21; ++i) {
        // account for capital letters too
        if (letter == consonants[i] || letter == consonants[i] - 32) {
            return true;
        }
    }

    return false;
}

void consonantReplace(char* word) {
    while (*word != '\0') {
        if (isConsonant(*word)) {
            *word = '$';
        }

        ++word;
    }
}