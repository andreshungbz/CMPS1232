#include <iostream>

char* strcpy(char* s1, const char* s2);

int main() {
    char input1[] {"goodbye"};
    char input2[] {"hello"};

    std::cout << "input1: " << input1 << '\n';
    std::cout << "input2: " << input2 << '\n';

    strcpy(input1, input2);
    std::cout << "input1 after strcpy(input1, input2): " << input1 << '\n';
    return 0;
}

char* strcpy(char* s1, const char* s2) {
    while (*s2 != '\0') {
        *s1++ = *s2++;
    }

    *s1 = '\0';

    return s1;
}