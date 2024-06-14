#include <iostream>
#include <vector>

template <typename T>
bool inArray(T value, std::vector<T> arr);

template <typename T>
void populate(std::vector<T>& arr);

template <typename T>
void print(const std::vector<T>& arr);

int main() {
    std::vector<int> numbers;

    populate(numbers);
    std::cout << '\n';
    print(numbers);

    return 0;
}

template <typename T>
bool inArray(T value, std::vector<T> arr) {
    for (T element : arr) {
        if (value == element) {
            return true;
        }
    }

    return false;
}

template <typename T>
void populate(std::vector<T>& arr) {
    const int times{20};
    for (std::size_t i{0}; i < times; ++i) {
        int number{};
        while (number < 10 || number > 100) {
            std::cout << '[' << i + 1 << "] " << "Enter a number between 10 and 100: ";
            std::cin >> number;
        }

        if (!inArray(number, arr)) {
            arr.push_back(number);
        }
    }
}

template <typename T>
void print(const std::vector<T>& arr) {
    bool first{true};
    for (int element : arr) {
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }

        std::cout << element;
    }

    std::cout << '\n';
}