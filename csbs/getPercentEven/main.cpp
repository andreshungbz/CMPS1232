#include <iostream>

double getPercentEven(const int array[], int length) {
    int evenCount{0};

    for (int i{0}; i < length; ++i) {
        if (array[i] % 2 == 0) {
            ++evenCount;
        }
    }

    if (length == 0) {
        return 0.0;
    }

    return (static_cast<double>(evenCount) / length) * 100;
}

int main() {
    const int arrSize{5};
    int a[arrSize] {6, 4, 9, 11, 5};

    std::cout << "getPercentEven: " << getPercentEven(a, arrSize) << '\n';

    return 0;
}
