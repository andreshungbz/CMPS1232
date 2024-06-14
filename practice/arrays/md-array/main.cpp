#include <iostream>

template <typename T>
void print3x3Array(const T arr[3][3], std::size_t rows, std::size_t cols);

template <typename T>
T findSum(T arr[3][3], std::size_t rows, std::size_t cols);

template <typename T>
T findProduct(T arr[3][3], std::size_t rows, std::size_t cols);

void printOddNumbers(int arr[3][3], std::size_t rows, std::size_t cols);

template <typename T>
T findSumDiagonal(const T arr[3][3], std::size_t rows, std::size_t cols);

int main() {
    const std::size_t rowSize{3};
    const std::size_t colSize{3};

    int array[rowSize][colSize] {
        {1, 2, 3},
        {5, 6, 7},
        {9, 10, 11}
    };

    std::cout << "Initial Array\n";
    print3x3Array(array, rowSize, colSize);
    std::cout << '\n';

    std::cout << "findSum: " << findSum(array, rowSize, colSize) << '\n';
    std::cout << "findProduct: " << findProduct(array, rowSize, colSize) << '\n';

    std::cout << "Odd Numbers: ";
    printOddNumbers(array, rowSize, colSize);
    std::cout << '\n';

    std::cout << "findSumDiagonal Output: ";
    int diagonalSum{findSumDiagonal(array, rowSize, colSize)};
    std::cout << "\nfindSumDiagonal Sum: " << diagonalSum << '\n';

    return 0;
}

template <typename T>
void print3x3Array(const T arr[3][3], std::size_t rows, std::size_t cols) {
    for (std::size_t i{0}; i < rows; ++i) {
        bool first{true};
        for (std::size_t j{0}; j < cols; ++j) {
            if (first) {
                first = false;
            } else {
                std::cout << ' ';
            }

            std::cout << arr[i][j];
        }

        std::cout << '\n';
    }
}

template <typename T>
T findSum(T arr[3][3], std::size_t rows, std::size_t cols) {
    T sum{0};

    for (std::size_t i{0}; i < rows; ++i) {
        for (std::size_t j{0}; j < cols; ++j) {
            sum += arr[i][j];
        }
    }

    return sum;
}

template <typename T>
T findProduct(T arr[3][3], std::size_t rows, std::size_t cols) {
    T product{1};

    for (std::size_t i{0}; i < rows; ++i) {
        for (std::size_t j{0}; j < cols; ++j) {
            product *= arr[i][j];
        }
    }

    return product;
}

void printOddNumbers(int arr[3][3], std::size_t rows, std::size_t cols) {
    bool first{true};

    for (std::size_t i{0}; i < rows; ++i) {
        for (std::size_t j{0}; j < cols; ++j) {
            if (first) {
                first = false;
            } else {
                if (arr[i][j] % 2 == 1) {
                    std::cout << ' ';
                }
            }

            if (arr[i][j] % 2 == 1) {
                std::cout << arr[i][j];
            }
        }
    }
}

template <typename T>
T findSumDiagonal(const T arr[3][3], std::size_t rows, std::size_t cols) {
    T sum{0};
    bool first{true};
    std::size_t colCounter{0};

    for (int i{static_cast<int>(rows) - 1}; i >= 0; --i) {
        if (first) {
            first = false;
        } else {
            std::cout << ' ';
        }

        std::cout << arr[i][colCounter];
        sum += arr[i][colCounter];
        ++colCounter;
    }

    return sum;
}
