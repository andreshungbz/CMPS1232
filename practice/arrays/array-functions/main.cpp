#include <iostream>

int sumArray(const int arr[], std::size_t len);
int largestInArray(const int arr[], std::size_t len);
int mostFrequent(const int arr[], std::size_t len);

int main() {
    const std::size_t size{5};
    int array[size] {8, 1, 6, 7, 1};

    std::cout << "Sum of Array: " << sumArray(array, size) << '\n';
    std::cout << "Largest in Array: " << largestInArray(array, size) << '\n';
    std::cout << "Most Frequent Element: " << mostFrequent(array, size) << '\n';

    return 0;
}

int sumArray(const int arr[], std::size_t len) {
    int sum{0};

    for (std::size_t i{0}; i < len; ++i) {
        sum += arr[i];
    }

    return sum;
}

int largestInArray(const int arr[], std::size_t len) {
    int largest{arr[0]};

    for (std::size_t i{1}; i < len; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int mostFrequent(const int arr[], std::size_t len) {
    int maxCount{0};
    int mostFrequent{arr[0]};

    for (std::size_t i{0}; i < len; ++i) {
        int count{0};

        for (std::size_t j{0}; j < len; ++j) {
            if (arr[i] == arr[j]) {
                ++count;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    return mostFrequent;
}