//
// Created by Andres Hung on 4/16/24.
//

#include "Account.h"

Account::Account() : accountNumber{}, balance{0.0} {}

Account::Account(const std::string& pAccountNumber, double pBalance) { // NOLINT(*-pro-type-member-init)
    setAccountNumber(pAccountNumber);
    setBalance(pBalance);
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}

void Account::setAccountNumber(const std::string& pAccountNumber) {
    accountNumber = pAccountNumber;
}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double pBalance) {
    balance = pBalance;
}