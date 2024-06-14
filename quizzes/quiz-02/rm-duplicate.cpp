#include <iostream>

template <typename T>
void printArray(const T arr[], std::size_t len);

template <typename T>
bool inArray(const T arr[], T element, std::size_t len);

template <typename T>
void eliminate_duplicates(T arr[], std::size_t len);

int main() {
    const std::size_t size{5};
    int array[size] {1, 2, 1, 5, 2};

    std::cout << "Before: ";
    printArray(array, size);
    std::cout << '\n';

    std::cout << "After: ";
    eliminate_duplicates(array, size);
    std::cout << '\n';

    return 0;
}

template <typename T>
void printArray(const T arr[], std::size_t len) {
    bool first{true};

    for (std::size_t i{0}; i < len; ++i) {
        if (first)
            first = false;
        else
            std::cout << ' ';

        std::cout << arr[i];
    }
}

template <typename T>
bool inArray(const T arr[], T element, std::size_t len) {
    for (std::size_t i{0}; i < len; ++i) {
        if (arr[i] == element)
            return true;
    }

    return false;
}

template <typename T>
void eliminate_duplicates(T arr[], std::size_t len) {
    std::size_t index{0};
    T newArray[len];

    for (std::size_t i{0}; i < len; ++i) {
        if (!inArray(newArray, arr[i], index)) {
            newArray[index] = arr[i];
            ++index;
        }
    }

    printArray(newArray, index);
}