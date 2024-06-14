#include <iomanip>
#include <iostream>

bool sorted(const double array[], int length) {
    bool sorted{true};

    for (int i{1}; i < length; ++i) {
        if (array[i] < array[i - 1]) {
            sorted = false;
            break;
        }
    }

    return sorted;
}

int main() {
    const int arrSize{6};
    double list[arrSize] {1.5, 4.3, 7.0, 19.5, 25.1, 46.2};

    std::cout << "sorted: " << std::boolalpha << sorted(list, arrSize) << '\n';

    return 0;
}
