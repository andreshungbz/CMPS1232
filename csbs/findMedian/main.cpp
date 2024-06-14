#include <iostream>

int findMedian(const int array[], int length) {
    int arrCopy[length];

    for (int i{0}; i < length; ++i) {
        arrCopy[i] = array[i];
    }

    for (int i{0}; i < length; ++i) {
        int smallest{arrCopy[i]};
        int smallestIndex{i};

        for (int j{i}; j < length; ++j) {
            if (arrCopy[j] < smallest) {
                smallest = arrCopy[j];
                smallestIndex = j;
            }
        }

        int temp{arrCopy[i]};
        arrCopy[i] = arrCopy[smallestIndex];
        arrCopy[smallestIndex] = temp;
    }

    return arrCopy[length / 2];
}

int main() {
    const int arrSize1{11};
    int list1[arrSize1] {5, 2, 4, 17, 55, 4, 3, 26, 18, 2, 17};

    const int arrSize2{15};
    int list2[arrSize2] {42, 37, 1, 97, 1, 2, 7, 42, 3, 25, 89, 15, 10, 29, 27};

    std::cout << "list1: " << findMedian(list1, arrSize1) << '\n';
    std::cout << "list2: " << findMedian(list2, arrSize2) << '\n';

    return 0;
}
