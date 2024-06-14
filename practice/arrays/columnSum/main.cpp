#include <iostream>

void printArray(const int array[][3], int rows, int cols) {
    for (int i{0}; i < rows; ++i) {
        for (int j{0}; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void sumToLastRow(int array[][3], int rows, int cols) {
    for (int i{0}; i < cols; ++i) {
        int sum{0};

        for (int j{0}; j < rows - 1; ++j) {
            sum += array[j][i];
        }

        array[rows - 1][i] = sum;
    }
}

int main() {
    const int rows{4};
    const int cols{3};

    int numbers[rows][cols] {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };

    std::cout << "Before:\n";
    printArray(numbers, rows, cols);

    sumToLastRow(numbers, rows, cols);

    std::cout << "\nAfter:\n";
    printArray(numbers, rows, cols);

    return 0;
}
