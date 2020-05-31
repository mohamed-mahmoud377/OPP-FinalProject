//
// Created by mohamed on 5/30/2020.
//

#ifndef OPP_FINALPROJECT_SAVINGSACCOUNT_H
#define OPP_FINALPROJECT_SAVINGSACCOUNT_H
#include "BankAccount.h"
enum Status{Active =1 ,Inactive=0 };
class SavingsAccount   : public BankAccount{
private:
    Status isActive;



public:
    SavingsAccount();

    bool withdraw(double withdraw) override;

    bool deposit(double deposit) override;

    void monthlyPro() override;

    ~SavingsAccount() override;


};


#endif //OPP_FINALPROJECT_SAVINGSACCOUNT_H
