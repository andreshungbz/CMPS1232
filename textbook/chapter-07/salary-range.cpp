#include <array>
#include <iostream>

std::size_t getSalaryIndex(double commission);

template <typename T, std::size_t N>
void recordSalaries(std::array<T, N>& salaries);

void printCategory(std::size_t category);

template <typename T, std::size_t N>
void printSalaries(const std::array<T, N>& salaries);

int main() {
    const int categoriesCount{9};
    std::array<int, categoriesCount> salaries{};

    std::cout << "07-10 Salesperson Salary Ranges";

    recordSalaries(salaries);
    printSalaries(salaries);

    return 0;
}

std::size_t getSalaryIndex(double commission) {
    const double categoryDifference{100.0};
    const double commissionPercent{0.09};

    std::size_t index{static_cast<std::size_t>((commission * commissionPercent) / categoryDifference)};
    return (index <= 8) ? index : 8;
}

template <typename T, std::size_t N>
void recordSalaries(std::array<T, N>& salaries) {
    while (true) {
        std::cout << "Enter salesperson's commission this week (-1 to quit): $";
        double commission;
        std::cin >> commission;

        if (commission < 0) break;

        ++salaries[getSalaryIndex(commission)];
    }
}

void printCategory(std::size_t category) {
    switch (category) {
        case 0:
            std::cout << "$200-299: ";
            break;
        case 1:
            std::cout << "$300-399: ";
            break;
        case 2:
            std::cout << "$400-499: ";
            break;
        case 3:
            std::cout << "$500-599: ";
            break;
        case 4:
            std::cout << "$600-699: ";
            break;
        case 5:
            std::cout << "$700-799: ";
            break;
        case 6:
            std::cout << "$800-899: ";
            break;
        case 7:
            std::cout << "$900-999: ";
            break;
        case 8:
            std::cout << "$1000 and over: ";
            break;
        default:
            std::cout << "Error: ";
    }
}

template <typename T, std::size_t N>
void printSalaries(const std::array<T, N>& salaries) {
    std::cout << "\nSalary Ranges:\n\n";

    for (std::size_t i{0}; i < salaries.size(); ++i) {
        printCategory(i);
        std::cout << salaries[i] << '\n';
    }
}