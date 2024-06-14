#include <cstring>
#include <iostream>

bool isVowel(char c);
void replacer(char* word);
void tokenizer(char* sentence);

int main() {
    char input[] {"a fun sentence this is"};

    tokenizer(input);

    return 0;
}

bool isVowel(const char c) {
    static char vowels[5] {'a', 'e', 'i', 'o', 'u'};

    for (std::size_t i{0}; i < 5; ++i) {
        if (c == *(vowels + i) || c + 32 == *(vowels + i)) {
            return true;
        }
    }

    return false;
}

void replacer(char* word) {
    while (*word != '\0') {
        if (isVowel(*word)) {
            *word = '$';
        }

        ++word;
    }
}

void tokenizer(char* sentence) {
    char* tokenPtr{std::strtok(sentence, " ")};

    while (tokenPtr) {
        std::cout << tokenPtr << ' ';
        replacer(tokenPtr);
        std::cout << tokenPtr << '\n';

        tokenPtr = std::strtok(nullptr, " ");
    }
}