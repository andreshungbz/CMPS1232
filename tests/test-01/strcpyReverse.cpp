#include <iostream>

void strcpyReverse(char target[], const char source[], int len);

int main() {
    char a[5] = "name";
    char b[5];

    strcpyReverse(b, a, 5);  // This will copy the content of array a into array b in REVERSE
    std::cout << "Original String: " << a << '\n';
    std::cout << "Reversed String: " << b << '\n';

    return 0;
}

void strcpyReverse(char target[], const char source[], int len) {
    int targetCounter{0};

    // use 2 to to skip null terminator
    for (int i{len - 2}; i >= 0; --i) {
        target[targetCounter++] = source[i];
    }

    // add null terminator to the end
    target[len - 1] = source[len - 1];
}