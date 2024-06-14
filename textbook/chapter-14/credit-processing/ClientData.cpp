//
// Created by Andres Hung on 4/14/24.
//

#include <string>
#include "ClientData.h"

ClientData::ClientData(int accountNumberValue, const std::string& lastName, const std::string& firstName, double balanceValue)
    : accountNumber(accountNumberValue), balance(balanceValue) {
    setLastName(lastName);
    setFirstName(firstName);
}

int ClientData::getAccountNumber() const {
    return accountNumber;
}

void ClientData::setAccountNumber(int accountNumberValue) {
    accountNumber = accountNumberValue;
}

std::string ClientData::getLastName() const {
    return lastName;
}

void ClientData::setLastName(const std::string& lastNameString) {
    std::size_t length{lastNameString.size()};
    length = (length < 15 ? length : 14);
    lastNameString.copy(lastName, length);
    lastName[length] = '\0';
}

std::string ClientData::getFirstName() const {
    return firstName;
}

void ClientData::setFirstName(const std::string& firstNameString) {
    std::size_t length{firstNameString.size()};
    length = (length < 10 ? length : 9);
    firstNameString.copy(firstName, length);
    firstName[length] = '\0';
}

double ClientData::getBalance() const {
    return balance;
}

void ClientData::setBalance(double balanceValue) {
    balance = balanceValue;
}