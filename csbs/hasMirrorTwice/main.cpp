#include <iomanip>
#include <iostream>

bool hasMirrorTwice(const int a1[], int a1Length, const int a2[], int a2Length) {
    int stopIndex{a1Length - a2Length};
    int a2Reverse[a2Length];

    int a2Index{0};
    for (int i{a2Length - 1}; i >= 0; --i) {
        a2Reverse[i] = a2[a2Index++];
    }

    int patternCount{0};

    for (int i{0}; i <= stopIndex; ++i) {
        int count{0};

        int a2Counter{0};
        for (int j{i}; j < i + a2Length; ++j) {
            int check1{a1[j]};
            int check2{a2Reverse[a2Counter]};

            ++a2Counter;

            if (check1 == check2) {
                ++count;
            }
        }

        if (count == a2Length) {
            ++patternCount;
        }
    }

    return patternCount >= 2;
}

int main() {
    int a1[] = {6, 1, 2, 1, 3, 1, 3, 2, 1, 5};
    int a2[] = {1, 2};

    int a3[] = {5, 8, 4, 18, 5, 42, 4, 8, 5, 5};
    int a4[] = {4, 8, 5};

    int a7[] = {6, 1, 2, 4, 2, 1, 2, 4, 2, 1, 5};
    int a8[] = {1, 2, 4, 2, 1};

    int a9[] = {0, 0};
    int aa[] = {0};

    std::cout << std::boolalpha << hasMirrorTwice(a1, 10, a2, 2) << ' '
        << hasMirrorTwice(a3, 10, a4, 3) << ' '
        << hasMirrorTwice(a7, 11, a8, 5) << ' '
        << hasMirrorTwice(a9, 2, aa, 1);

    return 0;
}
