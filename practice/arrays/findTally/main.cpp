#include <iostream>

void findTally(const int a[], int size);

int main() {
    const int size{6};
    int numbers[size] {1, 8, 1, 5, 6, 7};

    findTally(numbers, size);

    return 0;
}

void findTally(const int a[], int size) {
    const int tallyRows{2};

    // counter to keep track of the next element in tally
    int tallyCounter{0};

    int tally[tallyRows][size];

    for (int i{0}; i < size; ++i) {
        // check if value is already in tally
        bool inTally{false};

        for (int j{0}; j < tallyCounter; ++j) {
            if (a[i] == tally[0][j]) {
                inTally = true;
                break;
            }
        }

        // add to tally if new
        if (!inTally) {
            tally[0][tallyCounter] = a[i];
        } else {
            continue;
        }

        // count occurrences
        int count{0};
        for (int j{i}; j < size; ++j) {
            if (a[i] == a[j]) {
                ++count;
            }
        }

        // assign count and increment tallyCounter
        tally[1][tallyCounter++] = count;
    }

    // print tally according to tallyCounter
    for (int i{0}; i < tallyRows; ++i) {
        for (int j{0}; j < tallyCounter; ++j) {
            std::cout << tally[i][j] << ' ';
        }

        std::cout << '\n';
    }
}