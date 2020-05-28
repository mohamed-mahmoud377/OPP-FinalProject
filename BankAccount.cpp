//
// Created by mohamed on 5/28/2020.
//

#include "BankAccount.h"


BankAccount::BankAccount() {
    accountOwner = nullptr;
    balance = -1;
    startingBalance = -1;
    numOfDeposits = -1;
    numOfWithdrawals = -1;
    annualInterestRate =-1;
    monthlyServiceCharges=-1;
}



BankAccount::BankAccount(AccountOwner *accountOwner, double balance, double startingBalance, int numOfDeposits,
                         int numOfWithdrawals, double annualInterestRate, double monthlyServiceCharges) : accountOwner(
        accountOwner), balance(balance), startingBalance(startingBalance), numOfDeposits(numOfDeposits),
        numOfWithdrawals(numOfWithdrawals),annualInterestRate(annualInterestRate),monthlyServiceCharges(monthlyServiceCharges) {}

bool BankAccount::deposit(double deposit) {
    if(deposit<=0)
        return false;
    balance= balance+deposit;
    numOfDeposits++;
    return true;



}
bool BankAccount::withdraw(double withdraw) {
    if(withdraw<=0)
        return false;

    balance-=withdraw;
    numOfWithdrawals++;
}

void BankAccount::calInt() {
    // Monthly Interest Rate = (Annual Interest Rate / 12)
    //Monthly Interest = Balance * Monthly Interest Rate
    //Balance = Balance + Monthly Interest
    double monthlyRate = (annualInterestRate/12);
    monthlyRate *= balance;
    balance += monthlyRate;

}


void BankAccount::monthlyPro() {
    /*A virtual function that subtracts the monthly service charges from the balance, calls the calcInt function,
    and then sets the variables that hold the number of withdrawals, number of deposits,
    and monthly service charges to zero.*/
    balance -= monthlyServiceCharges;
    numOfWithdrawals=0;
    numOfDeposits =0;

}


AccountOwner *BankAccount::getAccountOwner() const {
    return accountOwner;
}







void BankAccount::setAccountOwner(AccountOwner *accountOwner) {
    BankAccount::accountOwner = accountOwner;
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::setBalance(double balance) {
    BankAccount::balance = balance;
}

double BankAccount::getStartingBalance() const {
    return startingBalance;
}

void BankAccount::setStartingBalance(double startingBalance) {
    BankAccount::startingBalance = startingBalance;
}

int BankAccount::getNumOfDeposits() const {
    return numOfDeposits;
}

void BankAccount::setNumOfDeposits(int numOfDeposits) {
    BankAccount::numOfDeposits = numOfDeposits;
}

int BankAccount::getNumOfWithdrawals() const {
    return numOfWithdrawals;
}

void BankAccount::setNumOfWithdrawals(int numOfWithdrawals) {
    BankAccount::numOfWithdrawals = numOfWithdrawals;
}

double BankAccount::getAnnualInterestRate() const {
    return annualInterestRate;
}

void BankAccount::setAnnualInterestRate(double annualInterestRate) {
    this->annualInterestRate = annualInterestRate;
}

double BankAccount::getMonthlyServiceCharges() const {
    return monthlyServiceCharges;
}

void BankAccount::setMonthlyServiceCharges(double monthlyServiceCharges) {
    this->monthlyServiceCharges = monthlyServiceCharges;
}




BankAccount::~BankAccount() {
    delete accountOwner;

}