#include <iostream>

void print1DArray(const int array[], int length);
void reverseArray(const int sourceArray[], int destArray[], int length);
void reverseArrayInPlace(int array[], int length);

int main() {
    const int size{10};
    int array1[size] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int array2[size];

    reverseArray(array1, array2, size);

    std::cout << "Array1: ";
    print1DArray(array1, size);
    std::cout << '\n';

    std::cout << "Array2: ";
    print1DArray(array2, size);
    std::cout << '\n';

    reverseArrayInPlace(array1, size);
    std::cout << "Array1 Reversed In Place: ";
    print1DArray(array1, size);
    std::cout << '\n';

    return 0;
}

void print1DArray(const int array[], int length) {
    bool first{true};

    for (int i{0}; i < length; ++i) {
        if (first) {
            first = false;
        } else {
            std::cout << ", ";
        }

        std::cout << array[i];
    }
}

void reverseArray(const int sourceArray[], int destArray[], int length) {
    int counter{length - 1};

    for (int i{0}; i < length; ++i) {
        destArray[i] = sourceArray[counter--];
    }
}

void reverseArrayInPlace(int array[], int length) {
    int iterations{length / 2};

    for (int i{0}; i < iterations; ++i) {
        int temp{array[i]};
        array[i] = array[length - i - 1];
        array[length - i - 1] = temp;
    }
}