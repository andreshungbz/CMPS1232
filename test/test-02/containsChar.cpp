#include <iostream>

bool search (char* inputArray, char c);

int main() {
    char sentence[] = "fluent in programming is tough but worth it!";
    bool result = search(sentence, 's');

    std::cout << "sentence: " << sentence << '\n';
    std::cout << "search(sentence, 's'): " << std::boolalpha << result << "\n\n";

    char sentence2[] = "where are you?";
    bool result2 = search(sentence2, 's');

    std::cout << "sentence2: " << sentence2 << '\n';
    std::cout << "search(sentence2, 's'): " << result2 << "\n\n";

    return 0;
}

bool search (char* inputArray, char c) {
    while (*inputArray != '\0') {
        if (*inputArray == c) {
            return true;
        }

        ++inputArray;
    }

    return false;
}