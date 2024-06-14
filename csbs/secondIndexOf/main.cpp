#include <iostream>

int secondIndexOf(const int array[], std::size_t length, int number) {
    int count{0};

    for (std::size_t i{0}; i < length; ++i) {
        if (array[i] == number) {
            ++count;

            if (count == 2) {
                return static_cast<int>(i);
            }
        }
    }

    return -1;
}

int main() {
    const std::size_t arrSize{11};
    int list[arrSize] {42, 7, -9, 14, 8, 39, 42, 8, 19, 0, 42};
    int number{42};

    std::cout << "secondIndexOf: " << secondIndexOf(list, arrSize, number) << '\n';

    return 0;
}
