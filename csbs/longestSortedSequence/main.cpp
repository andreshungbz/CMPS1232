#include <iostream>

int longestSortedSequence(const int array[], int length) {
    int sequence{0};
    int longestSeq{0};

    for (int i{0}; i < length; ++i) {
        if (i == 0) {
            ++sequence;
            longestSeq = sequence;
            continue;
        }

        if (array[i] >= array[i - 1]) {
            ++sequence;

            if (sequence >= longestSeq) {
                longestSeq = sequence;
            }
        } else {
            sequence = 1;
        }
    }

    return longestSeq;
}

int main() {
    const int arrSize1{13};
    int list1[arrSize1] {3, 8, 10, 1, 9, 14, -3, 0, 14, 207, 56, 98, 12};

    const int arrSize2{12};
    int list2[arrSize2] {17, 42, 3, 5, 5, 5, 8, 2, 4, 6, 1, 19};

    const int arrSize3{1};
    int list3[arrSize3] {1};

    std::cout << "list1: " << longestSortedSequence(list1, arrSize1) << '\n';
    std::cout << "list2: " << longestSortedSequence(list2, arrSize2) << '\n';
    std::cout << "list3: " << longestSortedSequence(list3, arrSize3) << '\n';
    std::cout << longestSortedSequence({}, 0) << '\n';

    return 0;
}
