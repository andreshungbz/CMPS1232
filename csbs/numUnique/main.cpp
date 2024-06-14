#include <iostream>

int numUnique(const int array[], int length) {
    int unique{0};

    for (int i{0}; i < length; ++i) {
        if (i == 0) {
            ++unique;
            continue;
        }

        if (array[i] > array[i - 1]) {
            ++unique;
        }
    }

    return unique;
}

int main() {
    const int arrSize{15};
    int list1[arrSize] {5, 7, 7, 7, 8, 22, 22, 23, 31, 35, 35, 40, 40, 40, 41};
    int list2[arrSize] {1, 2, 11, 17, 19, 20, 23, 24, 25, 26, 31, 34, 37, 40, 41};

    std::cout << "numUnique: " << numUnique(list1, arrSize) << '\n';
    std::cout << "numUnique: " << numUnique(list2, arrSize) << '\n';

    return 0;
}
