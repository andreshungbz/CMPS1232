#include <array>
#include <iostream>
#include <utility> // for std::swap, std::move

template <typename T, std::size_t N>
std::array<T, N> reverseArray(std::array<T, N> arr);

int main() {
    const int arrSize{10};
    std::array<int, arrSize> numbers{
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    std::array<int, arrSize> numbersCopy{reverseArray(numbers)};

    // boolean used to avoid printing a trailing space at the end of the loop
    bool first{true};

    for (const int number : numbersCopy) {
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }

        std::cout << number;
    }

    std::cout << std::endl;

    return 0;
}

template <typename T, std::size_t N>
std::array<T, N> reverseArray(std::array<T, N> arr) {
    // for keeping track of array from the end
    std::size_t sizeIndex{arr.size() - 1};
    // only half the array needs to be traversed to swap the values
    // truncation works for arrays with odd number of items (middle items doesn't need any swap)
    const std::size_t stopIndex{arr.size() / 2};

    for (std::size_t i{0}; i < stopIndex; ++i) {
        std::swap(arr[i], arr[sizeIndex--]);
    }

    return std::move(arr);
}