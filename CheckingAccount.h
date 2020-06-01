#pragma once
#include "BankAccount"
class CheckingAccount:public BankAccount
{
private:

public:
     CheckingAccount();
     bool withdraw(double withdraw)override;
     void monthlyProc()override;
    ~CheckingAccount();

};
