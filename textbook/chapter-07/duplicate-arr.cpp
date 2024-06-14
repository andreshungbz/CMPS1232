#include <array>
#include <iostream>

template <typename T, std::size_t N>
void populate(std::array<T, N>& arr, int times);

template <typename T, std::size_t N>
void print(const std::array<T, N>& arr);

int main() {
    const int maxSize{20};
    std::array<int, maxSize> numbers{};

    populate(numbers, maxSize);
    std::cout << '\n';
    print(numbers);

    return 0;
}

template <typename T, std::size_t N>
void populate(std::array<T, N>& arr, int times) {
    for (std::size_t i{0}; i < times; ++i) {
        int number{};
        while (number < 10 || number > 100) {
            std::cout << '[' << i + 1 << "] " << "Enter a number between 10 and 100: ";
            std::cin >> number;
        }

        bool inArray{false};
        for (int element : arr) {
            if (element == number) {
                inArray = true;
                break;
            }
        }

        if (!inArray) {
            arr[i] = number;
        }
    }
}

template <typename T, std::size_t N>
void print(const std::array<T, N>& arr) {
    for (int element : arr) {
        if (element >= 10 && element <= 100) {
            std::cout << element;
            std::cout << ' ';
        }
    }

    std::cout << '\n';
}