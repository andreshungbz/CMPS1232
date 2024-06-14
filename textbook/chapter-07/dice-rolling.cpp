#include <array>
#include <iostream>
#include <random>

int rollDie6();

template <typename T, std::size_t N>
void print(std::array<T, N> arr);

int main() {
    const int offset{2};
    const int combinations{11};
    const long rolls{36'000'000};
    std::array<int, combinations> tally{};

    for (long i{0}; i < rolls; ++i) {
        ++tally[rollDie6() + rollDie6() - offset];
    }

    print(tally);

    return 0;
}

int rollDie6() {
    static std::random_device rd{};
    static std::seed_seq ss{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    static std::mt19937 mt{ss};
    static std::uniform_int_distribution<> die6{1, 6};

    return die6(mt);
}

template <typename T, std::size_t N>
void print(const std::array<T, N> arr) {
    std::cout << "Tally Results\n";

    for (std::size_t i{0}; i < arr.size(); ++i) {
        std::cout << "Occurrences for sum " << i + 2 << ": " << arr[i] << '\n';
    }
}