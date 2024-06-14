#include <iostream>

int indexOf(const int array[], int length, int target) {
    int noIndex{-1};

    for (int i{0}; i < length; ++i) {
        if (array[i] == target) {
            return i;
        }
    }

    return noIndex;
}

int main() {
    const int arrSize{10};
    int array[arrSize] {42, 7, -9, 14, 8, 39, 42, 8, 19, 0};

    std::cout << "indexOf: " << indexOf(array, arrSize, 8) << '\n';
    return 0;
}
