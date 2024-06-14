#include <iostream>

void print(const int array[], int length) {
    for (int i{0}; i < length; ++i) {
        std::cout << "element [" << i << "] is " << array[i] << '\n';
    }
}

int main() {
    const int arrSize{5};
    int a[arrSize] {32, 5, 27, -3, 2598};

    print(a, arrSize);

    return 0;
}
