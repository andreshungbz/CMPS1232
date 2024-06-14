#include <iostream>

void print3ColArray(const int array[][3], int rows, int cols);
int findSmallest(const int array[][3], int rows, int cols);

int main() {
    const int ARRAY_SIZE{3};
    int table[ARRAY_SIZE][ARRAY_SIZE];

    for (int i{0}; i < ARRAY_SIZE; ++i) {
        for (int j{0}; j < ARRAY_SIZE; ++j) {
            std::cout <<  "Enter number for position [" << i << "][" << j << "] of ["
                      << ARRAY_SIZE << "][" << ARRAY_SIZE << "] array: ";
            int number;
            std::cin >> number;

            table[i][j] = number;
        }
    }

    std::cout << "\nYour Array\n";
    print3ColArray(table, ARRAY_SIZE, ARRAY_SIZE);

    std::cout << "\nfindSmallest Result: " << findSmallest(table, ARRAY_SIZE, ARRAY_SIZE) << '\n';

    return 0;
}

void print3ColArray(const int array[][3], int rows, int cols) {
    for (int i{0}; i < rows; ++i) {
        for (int j{0}; j < cols; ++j) {
            std::cout << array[i][j] << ' ';
        }

        std::cout << '\n';
    }
}

int findSmallest(const int array[][3], int rows, int cols) {
    int smallest{array[0][0]};

    for (int i{0}; i < rows; ++i) {
        for (int j{0}; j < cols; ++j) {
            if (array[i][j] < smallest) {
                smallest = array[i][j];
            }
        }
    }

    return smallest;
}