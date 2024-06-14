#include <iostream>
#include <string>

void printArray(const std::string array[], int length) {
    for (int i{0}; i < length; ++i) {
        std::cout << array[i] << ' ';
    }
}

void switchPairs(std::string array[], int length) {
    int indexStop{length % 2 == 0 ? length : length - 1};

    for (int i{0}; i < indexStop; i += 2) {
        std::string temp{array[i]};
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}

int main() {
    const int arrSize{7};
    std::string a[arrSize] {"a", "bb", "c", "ddd", "ee", "f", "g"};

    std::cout << "Before: ";
    printArray(a, arrSize);
    std::cout << '\n';

    switchPairs(a, arrSize);

    std::cout << "After: ";
    printArray(a, arrSize);
    std::cout << '\n';

    return 0;
}
