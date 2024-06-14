#include <iostream>

bool isVowel(const char c);
void replacer(char* sentence);

int main() {
    char input[] {"a fun sentence this is"};

    std::cout << "input: " << input << '\n';
    replacer(input);
    std::cout << "output: " << input << '\n';

    return 0;
}

bool isVowel(const char c) {
    switch(c) {
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

void replacer(char* sentence) {
    while (*sentence != '\0') {
        if (isVowel(*sentence)) {
            *(sentence) = '$';
        }

        ++sentence;
    }
}