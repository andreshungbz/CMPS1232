#include <cstring>
#include <iostream>

int stringInfo(const char* array, char c);
void stringInfo2(char* array, char c);
void stringInfo3(char* array);

int main() {
    char sentence[] {"This is a sentence with 7 tokens"};
    char sentenceCopy[] {"This is a sentence with 7 tokens"};

    std::cout << "sentence: " << sentence << '\n';
    std::cout << "stringInfo(sentence, 's'): " << stringInfo(sentence, 's') << '\n';

    stringInfo2(sentence, 's');
    std::cout << "stringInfo2(sentence, 's'): " << sentence << '\n';

    std::cout << "stringInfo3(sentenceCopy): " << sentenceCopy << '\n';
    stringInfo3(sentenceCopy);
    return 0;
}

int stringInfo(const char* array, const char c) {
    int count{0};

    while (*array != '\0') {
        if (*array == c) {
            ++count;
        }

        ++array;
    }

    return count;
}

void stringInfo2(char* array, const char c) {
    while (*array != '\0') {
        if (*array == c) {
            *array = '$';
        }

        ++array;
    }
}

void stringInfo3(char* array) {
    char* tokenPtr{std::strtok(array, " ")};

    while (tokenPtr != nullptr) {
        std::cout << tokenPtr << '\n';
        std::size_t length{std::strlen(tokenPtr)};
        std::cout << "length: " << length << '\n';

        // swap first and last letters
        char temp{*tokenPtr};
        *tokenPtr = *(tokenPtr + length - 1);
        *(tokenPtr + length - 1) = temp;

        std::cout << tokenPtr << "\n\n";

        tokenPtr = std::strtok(nullptr, " ");
    }
}