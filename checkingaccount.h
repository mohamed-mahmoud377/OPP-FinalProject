#pragma once
struct ServAndOwed {
    double servCharges;
    double totalOwed;
};
#include "BankAccount"
class CheckingAccount:public BankAccount
{
private:
    double owed;
    double serviceCharges;
public:
    CheckingAccount(double b, double air);
    double getAmountOwed() const;
    virtual void withdraw(double w);
    virtual ServAndOwed monthlyProc();

};
