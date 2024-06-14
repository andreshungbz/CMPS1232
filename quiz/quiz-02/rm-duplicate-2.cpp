#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr);

template <typename T>
void eliminate_duplicates(std::vector<T>& arr);

int main() {
    std::vector<int> array{1, 2, 1, 5, 2};

    std::cout << "Before: ";
    printArray(array);
    std::cout << '\n';

    eliminate_duplicates(array);

    std::cout << "After: ";
    printArray(array);
    std::cout << '\n';

    return 0;
}

template <typename T>
void printArray(const std::vector<T>& arr) {
    bool first{true};

    for (T element : arr) {
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }

        std::cout << element;
    }
}

template <typename T>
void eliminate_duplicates(std::vector<T>& arr) {
    // https://stackoverflow.com/a/1041939/22647886
    std::sort(arr.begin(), arr.end());
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
}