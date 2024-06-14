#include <iostream>
#include <random>

int rollDie6();
void populate(int arr[], int rolls);

int main() {
    const int faces{6};
    const int rolls{50};
    int frequency[faces] {};

    std::cout << "Rolling dice " << rolls << " times...\n\n";
    populate(frequency, rolls);

    for (int i{0}; i < faces; ++i) {
        std::cout << "Number of rolls for " << i + 1 << ": " << frequency[i] << '\n';
    }

    return 0;
}

int rollDie6() {
    static std::random_device rd{};
    static std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 mt{ss};
    static std::uniform_int_distribution<> dice{1, 6};

    return dice(mt);
}

void populate(int arr[], int rolls) {
    for (int i{1}; i <= rolls; ++i) {
        ++arr[rollDie6() - 1];
    }
}