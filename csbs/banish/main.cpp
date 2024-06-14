#include <iostream>

void printArray(const int array[], int length) {
    for (int i{0}; i < length; ++i) {
        std::cout << array[i] << ' ';
    }
}

bool inArray(const int array[], int length, int number) {
    for (int i{0}; i < length; ++i) {
        if (array[i] == number) {
            return true;
        }
    }

    return false;
}

void banish(int a1[], int a1Length, int a2[], int a2Length) {
    for (int i{0}; i < a1Length;) {
        if (inArray(a2, a2Length, a1[i])) {
            for (int j{i}; j < a1Length - 1; ++j) {
                a1[j] = a1[j + 1];
            }

            a1[a1Length - 1] = 0;
            continue;
        }

        ++i;
    }
}

int main() {
    const int arrSize1{17};
    const int arrSize2{3};
    int a1[arrSize1] {42, 3, 9, 42, 42, 0, 42, 9, 42, 42, 17, 8, 2222, 4, 9, 0, 1};
    int a2[arrSize2] {42, 2222, 9};

    banish(a1, arrSize1, a2, arrSize2);

    printArray(a1, arrSize1);

    return 0;
}
