#include <iostream>

int countUnique(const int array[], std::size_t length) {
    int unique{0};

    for (int i{0}; i < length; ++i) {
        // only for the first element increment unique count
        if (i == 0) {
            ++unique;
            continue;
        }

        bool isUnique{true};
        for (int j{0}; j < i; ++j) {
            if (array[j] == array[i]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            ++unique;
        }
    }

    return unique;
}

int main() {
    const std::size_t arrSize{8};
    int numbers[arrSize] {7, 7, 2, 2, 1, 2, 2, 7};

    std::cout << "countUnique: " << countUnique(numbers, arrSize) << '\n';

    return 0;
}
