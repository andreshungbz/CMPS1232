#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "ClientData.h"

void outputLine(std::ostream&, const ClientData&);

int main() {
    std::ifstream inCredit{"../credit.dat", std::ios::in | std::ios::binary};

    if (!inCredit) {
        std::cerr << "File could not be opened." << std:: endl;
        std::exit(EXIT_FAILURE);
    }

    std::cout << std::left << std::setw(10) << "Account" << std::setw(16) << "Last Name"
        << std::setw(11) << "First Name" << std::setw(10) << std::right << "Balance\n";

    ClientData client;

    inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    while (inCredit) {
        if (client.getAccountNumber() != 0) {
            outputLine(std::cout, client);
        }

        inCredit.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }

    return 0;
}

void outputLine(std::ostream& output, const ClientData& record) {
    output << std::left << std::setw(10) << record.getAccountNumber()
        << std::setw(16) << record.getLastName()
        << std::setw(11) << record.getFirstName()
        << std::setw(10) << std::setprecision(2) << std::right << std::fixed
        << std::showpoint << record.getBalance() << std::endl;
}