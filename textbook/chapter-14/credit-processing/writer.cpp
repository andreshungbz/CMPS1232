#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"

int main() {
    std::fstream outCredit{"../credit.dat", std::ios::in | std::ios::out | std::ios::binary};

    if (!outCredit) {
        std::cerr << "File could not be opened." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";

    int accountNumber;
    std::string lastName;
    std::string firstName;
    double balance;

    std::cin >> accountNumber;

    while (accountNumber > 0 && accountNumber <= 100) {
        std::cout << "Enter lastname, firstname and balance\n? ";
        std::cin >> lastName >> firstName >> balance;

        ClientData client{accountNumber, lastName, firstName, balance};

        outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));

        outCredit.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));

        std::cout << "Enter account number\n? ";
        std::cin >> accountNumber;
    }

    return 0;
}
