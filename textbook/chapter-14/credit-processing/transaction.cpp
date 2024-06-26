#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "ClientData.h"

enum class Choice {
    PRINT = 1,
    UPDATE,
    NEW,
    DELETE,
    END
};

Choice enterChoice();
void createTextFile(std::fstream&);
void updateRecord(std::fstream&);
void newRecord(std::fstream&);
void deleteRecord(std::fstream&);
void outputLine(std::ostream&, const ClientData&);
int getAccount(const char* const);

int main() {
    std::fstream inOutCredit{"../credit.dat", std::ios::in | std::ios::out | std::ios::binary};

    if (!inOutCredit) {
        std::cerr << "File could not be opened." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    Choice choice;

    while ((choice = enterChoice()) != Choice::END) {
        switch (choice) {
            case Choice::PRINT:
                createTextFile(inOutCredit);
                break;
            case Choice::UPDATE:
                updateRecord(inOutCredit);
                break;
            case Choice::NEW:
                newRecord(inOutCredit);
                break;
            case Choice::DELETE:
                deleteRecord(inOutCredit);
                break;
            default:
                std::cerr << "Incorrect choice" << std::endl;
        }

        inOutCredit.clear();
    }

    return 0;
}

Choice enterChoice() {
    std::cout << "\nEnter your choice\n"
        << "1 - store a formatted text file of accounts\n"
        << "    called \"print.txt\" for printing\n"
        << "2 - update an account\n"
        << "3 - add a new account\n"
        << "4 - delete an account\n"
        << "5 - end program\n? ";

    int menuChoice;
    std::cin >> menuChoice;

    return static_cast<Choice>(menuChoice);
}

void createTextFile(std::fstream& readFromFile) {
    std::ofstream outPrintFile("../print.txt", std::ios::out);

    if (!outPrintFile) {
        std::cerr << "File could not be created." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    outPrintFile << std::left << std::setw(10) << "Account" << std::setw(16)
        << "Last Name" << std::setw(11) << "First Name" << std::right
        << std::setw(10) << "Balance" << std::endl;

    readFromFile.seekg(0, std::ios::beg);

    ClientData client;
    readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    while (!readFromFile.eof()) {
        if (client.getAccountNumber() != 0) {
            outputLine(outPrintFile, client);
        }

        readFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));
    }
}

void updateRecord(std::fstream& updateFile) {
    int accountNumber{getAccount("Enter account to update")};

    updateFile.seekg((accountNumber - 1) * sizeof(ClientData));

    ClientData client;
    updateFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if (client.getAccountNumber() != 0) {
        outputLine(std::cout, client);

        std::cout << "\nEnter charge (+) or payment (-): ";
        double transaction;
        std::cin >> transaction;

        double oldBalance = client.getBalance();
        client.setBalance(oldBalance + transaction);
        outputLine(std::cout, client);

        updateFile.seekp((accountNumber - 1) * sizeof(ClientData));
        updateFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
    } else {
        std::cerr << "Account #" << accountNumber
            << " has no information." << std::endl;
    }
}

void newRecord(std::fstream& insertInFile) {
    int accountNumber{getAccount("Enter new account number")};

    insertInFile.seekg((accountNumber - 1) * sizeof(ClientData));

    ClientData client;
    insertInFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if (client.getAccountNumber() == 0) {
        std::string lastName;
        std::string firstName;
        double balance;

        std::cout << "Enter lastname, firstname, balance\n? ";
        std::cin >> std::setw(15) >> lastName;
        std::cin >> std::setw(10) >> firstName;
        std::cin >> balance;

        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);
        client.setAccountNumber(accountNumber);

        insertInFile.seekp((accountNumber - 1) * sizeof(ClientData));
        insertInFile.write(reinterpret_cast<const char*>(&client), sizeof(ClientData));
    } else {
        std::cerr << "Account #" << accountNumber
            << " already contains information." << std::endl;
    }
}

void deleteRecord(std::fstream& deleteFromFile) {
    int accountNumber{getAccount("Enter account to delete")};

    deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData));

    ClientData client;
    deleteFromFile.read(reinterpret_cast<char*>(&client), sizeof(ClientData));

    if (client.getAccountNumber() != 0) {
        ClientData blankClient;

        deleteFromFile.seekp((accountNumber - 1) * sizeof(ClientData));
        deleteFromFile.write(reinterpret_cast<const char*>(&blankClient), sizeof(ClientData));

        std::cout << "Account #" << accountNumber << " deleted.\n";
    } else {
        std::cerr << "Account #" << accountNumber << " is empty.\n";
    }
}

void outputLine(std::ostream& output, const ClientData& record) {
    output << std::left << std::setw(10) << record.getAccountNumber()
           << std::setw(16) << record.getLastName()
           << std::setw(11) << record.getFirstName()
           << std::setw(10) << std::setprecision(2) << std::right << std::fixed
           << std::showpoint << record.getBalance() << std::endl;
}

int getAccount(const char* const prompt) {
    int accountNumber;

    do {
        std::cout << prompt << " (1 - 100): ";
        std::cin >> accountNumber;
    } while (accountNumber < 1 || accountNumber > 100);

    return accountNumber;
}