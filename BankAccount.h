//
// Created by mohamed on 5/28/2020.
//

#ifndef PROGRAM305_OOPPROJECT_BANKACCOUNT_H
#define PROGRAM305_OOPPROJECT_BANKACCOUNT_H


#include "AccountOwner.h"
class AccountOwenr;
class BankAccount {
protected:
    AccountOwner *accountOwner;
    double balance;
    double startingBalance;

    int numOfDeposits;
    int numOfWithdrawals;
    double annualInterestRate;
    double monthlyServiceCharges ;
    double monthlyInterestRate;
    string type;

public:


    BankAccount(AccountOwner *accountOwner, double balance, double startingBalance, int numOfDeposits,
                int numOfWithdrawals, double annualInterestRate, double monthlyServiceCharges);

    BankAccount();


    virtual bool deposit(double deposit);

    virtual bool withdraw(double withdraw);
    virtual void calInt();
    virtual void monthlyPro();
    virtual void displayMonthStatistics()=0 ;





    AccountOwner *getAccountOwner() const;

    void setAccountOwner(AccountOwner *accountOwner);

    double getBalance() const;

    bool setBalance(double balance);

    double getStartingBalance() const;

    void setStartingBalance(double startingBalance);

    int getNumOfDeposits() const;

    void setNumOfDeposits(int numOfDeposits);

    int getNumOfWithdrawals() const;

    void setNumOfWithdrawals(int numOfWithdrawals);

    double getAnnualInterestRate() const;

    bool setAnnualInterestRate(double annualInterestRate);

    double getMonthlyServiceCharges() const;


    void setMonthlyServiceCharges(double monthlyServiceCharges);

    const string &getType() const;

    void setType(const string &type);

    double getMonthlyInterestRate() const;

    void setMonthlyInterestRate();


    virtual ~BankAccount();
};


#endif //PROGRAM305_OOPPROJECT_BANKACCOUNT_H
