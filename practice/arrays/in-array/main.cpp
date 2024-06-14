#include <iostream>

int getNumber();
bool inArray(int number, const int arr[], std::size_t len);

int main() {
    const std::size_t length{5};
    int numbers[length] {1, 2, 3, 4, 5};

    int number{getNumber()};

    std::cout << "The number " << number << " IS"
        << (inArray(number, numbers, length) ? "" : " NOT") << " in the array\n";

    return 0;
}

int getNumber() {
    std::cout << "Enter a number: ";
    int number;
    std::cin >> number;

    return number;
}

bool inArray(int number, const int arr[], std::size_t len) {
    for (std::size_t i{0}; i < len; ++i) {
        if (number == arr[i]) {
            return true;
        }
    }

    return false;
}