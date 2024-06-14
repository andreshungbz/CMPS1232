#include <iostream>
#include <string>

template <typename T>
void printArray(const T array[], std::size_t length) {
    bool first{true};
    for (std::size_t i{0}; i < length; ++i) {
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }

        std::cout << '"' << array[i] << '"';
    }
}

bool isPalindrome(const std::string& word) {
    std::string test{word};

    for (char& c : test) {
        c = static_cast<char>(std::tolower(c));
    }

    std::string reversed{};

    for (int i{static_cast<int>(test.length() - 1)}; i >= 0; --i) {
        reversed += test[i];
    }

    return reversed == test;
}

void removePalindromes(std::string array[], std::size_t length) {
    for (std::size_t i{0}; i < length; ++i) {
        if (isPalindrome(array[i])) {
            array[i] = "";
        }
    }
}

int main() {
    const std::size_t arrSize{13};
    std::string a[arrSize] {"Madam", "raceCAR", "", "hi", "A", "Abba", "banana", "dog God",
                            "STOP otto POTS", "Madame", "C++", "LevEL", "staTS"};

    std::cout << "Before: ";
    printArray(a, arrSize);
    std::cout << '\n';

    removePalindromes(a, arrSize);

    std::cout << "After: ";
    printArray(a, arrSize);
    std::cout << '\n';

    return 0;
}
