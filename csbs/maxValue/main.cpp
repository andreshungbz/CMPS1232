#include <iostream>

int maxValue(const int array[], int length) {
    int max{array[0]};

    for (int i{1}; i < length; ++i) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}

int main() {
    const int arrSize{6};
    int array[arrSize] {17, 7, -1, 26, 3, 9};

    std::cout << "maxValue: " << maxValue(array, arrSize) << '\n';

    return 0;
}
