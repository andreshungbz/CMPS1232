#include <cstring>
#include <iostream>

void printer(const char* word);
void tokenizer(char* sentence);

int main() {
    char input[] {"a fun sentence this is"};

    std::cout << "Input: " << input << '\n';
    tokenizer(input);

    return 0;
}

void printer(const char* word) {
    std::size_t length{std::strlen(word)};

    if (length < 4) {
        for (std::size_t i{0}; i < length; ++i) {
            std::cout << '$';
        }
    } else {
        for (std::size_t i{0}; i < length; ++i) {
            std::cout << '#';
        }
    }
}

void tokenizer(char* sentence) {
    char* token{std::strtok(sentence, " ")};

    while (token) {
        std::cout << token << ' ';
        printer(token);
        std::cout << '\n';

        token = std::strtok(nullptr, " ");
    }
}