#include "CheckingAccount.h"
CheckingAccount()
    {
    balance = -1;
    numOfWithdrawals = -1;
    monthlyServiceCharges=-1;
    }

}
bool checkingAccount::withdraw(double withdraw)
{
        if(withdraw > balance){
            cout << "Withdrawal failed! ";
            cout << withdraw << " but current balance is $" << balance;
            cout << "You will be charged $15.00 for this";
            balance -= 15.0;
        }
        else{
                return false;
                return BankAccount::withdraw(double withdraw);
            }

}

void CheckingAccount::monthlyProc() {

    serviceCharges += (5.00 + (withdrawals*.10));
    monthlyServiceCharges+=serviceCharges;
    BankAccount::monthlyProc();

}
