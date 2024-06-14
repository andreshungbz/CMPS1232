#include <iostream>

bool inArray(const int array[], int number, int length) {
    for (int i{0}; i < length; ++i) {
        if (array[i] == number) {
            return true;
        }
    }

    return false;
}

int countDuplicates(const int array[], int length) {
    int duplicates{0};

    // keep track of checked values
    int checked[length];
    int checkedIndex{0};

    for (int i{0}; i < length; ++i) {
        // skip checked values
        if (inArray(checked, array[i], checkedIndex)) {
            continue;
        }

        for (int j{i + 1}; j < length; ++j) {
            if (array[j] == array[i]) {
                ++duplicates;
            }
        }

        checked[checkedIndex++] = array[i];
    }

    return duplicates;
}

int main() {
    const int arrSize{12};
    int array[arrSize] {1, 4, 2, 4, 7, 1, 1, 9, 2, 3, 4, 1};

    std::cout << "countDuplicates: " << countDuplicates(array, arrSize);

    return 0;
}
