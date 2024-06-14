#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "Account.h"

int main() {
    std::ofstream oAccounts{"../accountsData.dat", std::ios::out | std::ios::binary};

    if (!oAccounts) {
        std::cerr << "File could not be opened.";
        std::exit(EXIT_FAILURE);
    }

    Account account{};

    while (true) {
        std::cout << "Enter account number (n to stop): ";
        std::string newAccountNumber;
        std::getline(std::cin >> std::ws, newAccountNumber);

        if (newAccountNumber == "n" || newAccountNumber == "N") break;

        std::cout << "Enter balance: ";
        double newBalance;
        std::cin >> newBalance;

        account.setAccountNumber(newAccountNumber);
        account.setBalance(newBalance);

        oAccounts.seekp((std::stoi(account.getAccountNumber()) - 1) * sizeof(Account));
        oAccounts.write(reinterpret_cast<const char*>(&account), sizeof(Account));
    }

    oAccounts.close();

    // READING

    std::ifstream iAccounts{"../accountsData.dat", std::ios::in};

    if (!iAccounts) {
        std::cerr << "File could not be opened";
        std::exit(EXIT_FAILURE);
    }

    Account retrievedAccount{};

    std::cout << "\nEnter your account number to get data: ";
    int number;
    std::cin >> number;

    iAccounts.seekg((number - 1) * sizeof(Account));
    iAccounts.read(reinterpret_cast<char*>(&retrievedAccount), sizeof(Account));

    iAccounts.close();

    // WRITING TO TXT FILE

    std::ofstream txtAccounts("../accountPrinted.txt", std::ios::out);

    txtAccounts << "Account number: " << retrievedAccount.getAccountNumber() << '\n'
        << "Account balance: " << retrievedAccount.getBalance() << '\n';

    txtAccounts.close();

    std::cout << "Account information written to accountsPrinted.txt\n";

    return 0;
}
