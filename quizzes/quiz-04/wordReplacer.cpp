#include <iostream>

std::size_t my_strlen(const char* string);
void replacer(char* string);

int main() {
    char input1[] {"fun"};
    char input2[] {"funny"};

    std::cout << "input1: " << input1 << '\n';
    replacer(input1);
    std::cout << "output1: " << input1 << '\n';

    std::cout << "input2: " << input2 << '\n';
    replacer(input2);
    std::cout << "output2: " << input2 << '\n';

    return 0;
}

std::size_t my_strlen(const char* string) {
    std::size_t length{0};

    while (*string != '\0') {
        ++length;
        ++string;
    }

    return length;
}

void replacer(char* string) {
    std::size_t length{my_strlen(string)};

    if (length < 4) {
        for (std::size_t i{0}; i < length; ++i) {
            *(string + i) = '$';
        }
    } else {
        for (std::size_t i{0}; i < length; ++i) {
            *(string + i) = '#';
        }
    }
}