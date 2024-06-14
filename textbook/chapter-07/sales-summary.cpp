#include <array>
#include <iomanip>
#include <iostream>
#include <string>

namespace Store {
    struct Product {
        int number{};
        int value{};
    };

    const std::size_t salespeopleCount{4};
    const std::size_t productCount{5};

    constexpr std::array<Product, productCount> catalogue{
        Product{0, 100},
        Product{1, 200},
        Product{2, 300},
        Product{3, 400},
        Product{4, 500}
    };
}

template <typename T, std::size_t N, std::size_t M>
void monthlySales(std::array<std::array<T, N>, M>& sales);

template <typename T, std::size_t N, std::size_t M>
void salesSummary(const std::array<std::array<T, N>, M>& sales);

int main() {
    std::cout << "7-21 Sales Summary\n\n";
    std::array<std::array<int, Store::productCount>, Store::salespeopleCount> sales{};

    monthlySales(sales);
    salesSummary(sales);

    return 0;
}

template <typename T, std::size_t N, std::size_t M>
void monthlySales(std::array<std::array<T, N>, M>& sales) {
    for (std::size_t salesperson{0}; salesperson < Store::salespeopleCount; ++salesperson) {
        for (std::size_t product{0}; product < Store::productCount; ++product) {
            int total{0};

            std::cout << "[Salesperson " << salesperson + 1
                      << "] [Product " << product + 1 << "] Sales Count for Month: ";
            std::cin >> total;

            /* for individual payslips
            while (true) {
                std::cout << "[Salesperson " << salesperson + 1
                    << "] [Product " << product + 1 << "] Sale Count for Day (-1 when done): ";
                int sale;
                std::cin >> sale;

                if (sale < 0) break;

                total += sale;
            }
            */

            sales[salesperson][product] = total * Store::catalogue[product].value;
        }

        std::cout << '\n';
    }
}

template <typename T, std::size_t N, std::size_t M>
void salesSummary(const std::array<std::array<T, N>, M>& sales) {
    const int w{13}; // common width

    std::cout << "Monthly Summary\n";

    // column labels
    bool first{true}; // for table organization
    std::cout << std::setw(w + 12) << std::right;
    for (std::size_t i{0}; i < Store::productCount; ++i) {
        if (first) {
            first = false;
        } else {
            std::cout << std::setw(w - 1) << std::right;
        }
        std::cout << "Product " << i + 1;
    }
    std::cout << std::setw(w + 2) << std::right << "TOTAL\n";

    // salesperson product totals and overall total
    std::array <int, Store::productCount> productTotal{};
    for (std::size_t row{0}; row < Store::salespeopleCount; ++row) {
        int salespersonTotal{0};
        std::cout << std::left << std::setw(w) << ("Salesperson " + std::to_string(row + 1));
        for (std::size_t col{0}; col < Store::productCount; ++col) {
            std::cout << std::setw(w) << std::right << ('$' + std::to_string(sales[row][col]));

            salespersonTotal += sales[row][col];
            productTotal[col] += sales[row][col];
        }
        std::cout << std::setw(w + 1) << std::right << ('$' + std::to_string(salespersonTotal)) << '\n';
    }

    // product totals
    std::cout << std::setw(w) << std::right << "TOTAL";
    for (int total : productTotal) {
        std::cout << std::setw(w) << std::right << ('$' + std::to_string(total));
    }

    std::cout << '\n';
}