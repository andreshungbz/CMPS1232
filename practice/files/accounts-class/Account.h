//
// Created by Andres Hung on 4/16/24.
//

#ifndef ACCOUNTS_CLASS_ACCOUNT_H
#define ACCOUNTS_CLASS_ACCOUNT_H


#include <string>

class Account {
public:
    Account();
    explicit Account(const std::string& pAccountNumber, double pBalance);
    [[nodiscard]] std::string getAccountNumber() const;
    void setAccountNumber(const std::string& pAccountNumber);
    [[nodiscard]] double getBalance() const;
    void setBalance(double pBalance);
private:
    std::string accountNumber;
    double balance;
};


#endif // ACCOUNTS_CLASS_ACCOUNT_H
