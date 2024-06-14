#include <iostream>

void print50ColArray(const int array[][50], int rows, int cols);
void sumRows(int array[][50], int rows, int cols);

int main() {
    const int rows{50};
    const int cols{50};
    int numbers[rows][cols] {
        {1, 2},
        {3, 4}
    };

    sumRows(numbers, rows, cols);

    std::cout << "sumRows Result\n";
    print50ColArray(numbers, rows, cols);

    return 0;
}

void print50ColArray(const int array[][50], int rows, int cols) {
    for (int i{0}; i < rows; ++i) {
        for (int j{0}; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

void sumRows(int array[][50], int rows, int cols) {
    for (int i{0}; i < rows; ++i) {
        int sum{0};

        for (int j{0}; j < cols - 1; ++j) {
            sum += array[i][j];
        }

        array[i][cols - 1] = sum;
    }
}