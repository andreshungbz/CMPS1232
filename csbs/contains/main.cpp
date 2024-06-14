#include <iomanip>
#include <iostream>

bool contains(const int a1[], int a1Length, const int a2[], int a2Length) {
    int stopIndex{a1Length - a2Length};

    for (int i{0}; i <= stopIndex; ++i) {
        int counter{0};
        int a2Index{0};

        for (int j{i}; j < i + a2Length; ++j) {
            if (a1[j] == a2[a2Index++]) {
                ++counter;
            }
        }

        if (counter == a2Length) {
            return true;
        }
    }

    return false;
}

int main() {
    const int arrSize1{9};
    const int arrSize2{3};
    int a1[arrSize1] {1, 6, 2, 1, 4, 1, 2, 1, 8};
    int a2[arrSize2] {1, 2, 1};

    std::cout << "contains: " << std::boolalpha << contains(a1, arrSize1, a2, arrSize2) << '\n';

    return 0;
}
