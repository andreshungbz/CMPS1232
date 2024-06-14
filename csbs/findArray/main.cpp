#include <iostream>

int findRange(const int array[], int length) {
    int smallest{array[0]};
    int largest{array[0]};

    for (int i{1}; i < length; ++i) {
        if (array[i] < smallest) {
            smallest = array[i];
        }

        if (array[i] > largest) {
            largest = array[i];
        }
    }

    return largest - smallest + 1;
}

int main() {
    const int arrSize{3};
    int array[arrSize] {17, 8, 6};

    std::cout << "findRange: " << findRange(array, arrSize) << '\n';

    return 0;
}
