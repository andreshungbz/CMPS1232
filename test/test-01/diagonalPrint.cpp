#include <iostream>

void print(const int array[][3], int rows, int cols);

int main () {
    const int rows{3};
    const int cols{3};
    int array[rows][cols] {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    print(array, rows, cols);
    std::cout << '\n';

    return 0;
}

void print(const int array[][3], int rows, int cols) {
    bool first{true};

    for (int i{0}; i < rows; ++i) {
        if (first) {
            first = false;
        } else {
            std::cout << ',';
        }

        std::cout << array[i][cols - 1 - i];
    }
}