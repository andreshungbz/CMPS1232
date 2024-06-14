#include <iomanip>
#include <iostream>
#include <array>

template <typename T, std::size_t N>
void populate(std::array<T, N>& arr);

template <typename T, std::size_t N>
double getAverage(const std::array<T, N>& arr);

int main() {
    const int count{10};
    std::array<int, count> numbers{};

    populate(numbers);
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "The average of the numbers in the array is: " << getAverage(numbers) << '\n';

    return 0;
}

template <typename T, std::size_t N>
void populate(std::array<T, N>& arr) {
    for (std::size_t i{0}; i < arr.size(); ++i) {
        std::cout << '[' << i + 1 << "] Enter number: ";
        T value{};
        std::cin >> value;

        arr[i] = value;
    }
}

template <typename T, std::size_t N>
double getAverage(const std::array<T, N>& arr) {
    T total = 0;
    for (T value : arr) {
        total += value;
    }

    return static_cast<double>(total) / arr.size();
}