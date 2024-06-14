#include <iomanip>
#include <iostream>

double computeAverage(const int array[], std::size_t length) {
    int sum{0};

    for (std::size_t i{0}; i < length; ++i) {
        sum += array[i];
    }

    return static_cast<double>(sum) / static_cast<double>(length);
}

int main() {
    const std::size_t arrSize{10};
    int array[arrSize] {1, -2, 4, -4, 9, -6, 16, -8, 25, -10};

    std::cout << "computeAverage: " << std::setprecision(1) << std::fixed
        << computeAverage(array, arrSize) << '\n';

    return 0;
}
