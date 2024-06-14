#include <iostream>

void printArray(const int a[], int len) {
    for (int i{0}; i < len; ++i) {
        std::cout << a[i] << ' ';
    }
}

void collapsePairs(int a[], int len) {
    int stopIndex{len % 2 == 0 ? len : len - 2};

    for (int i{0}; i < stopIndex; i += 2) {
        int sum{a[i] + a[i + 1]};

        if (sum % 2 == 0) {
            a[i] = sum;
            a[i + 1] = 0;
        } else {
            a[i + 1] = sum;
            a[i] = 0;
        }
    }
}

int main() {
    const int arrSize{10};
    int values[arrSize] {7, 2, 8, 9, 4, 22, 7, 1, 9, 10};

    collapsePairs(values, arrSize);

    printArray(values, arrSize);

    return 0;
}
