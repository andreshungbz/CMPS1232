#include <iostream>

int findMaximum(const int array[][3], int rows, int cols);

int main () {
    const int rows{3};
    const int cols{3};
    int array[rows][cols] {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    std::cout << "findMaximum result: " << findMaximum(array, rows, cols) << '\n';

    return 0;
}

int findMaximum(const int array[][3], int rows, int cols) {
    int sums[rows];

    for (int i{0}; i < rows; ++i) {
        int sum{0};

        for (int j{0}; j < cols; ++j) {
            sum += array[i][j];
        }

        sums[i] = sum;
    }

    int maximumIndex{0};

    for (int i{0}; i < rows; ++i) {
        if (sums[i] > sums[maximumIndex]) {
            maximumIndex = i;
        }
    }

    return maximumIndex;
}
