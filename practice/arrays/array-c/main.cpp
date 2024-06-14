#include <iostream>
#include <iomanip>

void populateArray(int arr[], int length) {
    for (int i{0}; i < length; ++i) {
        std::cout << '[' << i + 1 << "] Enter a number: ";
        int number;
        std::cin >> number;

        arr[i] = number;
    }
}

double getAverage(const int arr[], int length) {
    int sum{0};

    for (int i{0}; i < length; ++i) {
        sum += arr[i];
    }

    return static_cast<double>(sum) / length;
}

int main() {
    const int size{10};
    int array[size];

    populateArray(array, size);

    std::cout << "Average: " << std::fixed << std::setprecision(2) << getAverage(array, size) << '\n';

    return 0;
}
