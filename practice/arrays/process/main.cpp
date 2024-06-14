#include <iostream>

int process(const int a[], const int b[], int size);

int main() {
    const int size{5};
    int array1[size] {1, 2, 3, 4, 5};
    int array2[size] {47, 48, 49, 50, 51};

    std::cout << "process: " << process(array1, array2, size) << '\n';

    return 0;
}

int process(const int a[], const int b[], int size) {
    const int rows{3};
    int temp[rows][size];

    // first array
    for (int i{0}; i < size; ++i) {
        temp[0][i] = a[i];
    }

    // second array
    for (int i{0}; i < size; ++i) {
        temp[1][i] = b[i];
    }

    // sum to last row
    for (int i{0}; i < size; ++i) {
        int sum{0};

        for (int j{0}; j < rows - 1; ++j) {
            sum += temp[j][i];
        }

        temp[rows - 1][i] = sum;
    }

    // determine counter
    int counter50 {0};
    for (int i{0}; i < rows; ++i) {
        for (int j{0}; j < size; ++j) {
            if (temp[i][j] > 50) {
                ++counter50;
            }
        }
    }

    return counter50;
}