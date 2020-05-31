#include "CheckingAccount.h"
CheckingAccount::CheckingAccount()
{
    BankAccount()
    {
        owed = 0.0;
    }
}
double CheckingAccount::getAmountOwed() const {
    return owed;
}
void CheckingAccount::withdraw(double w) {
    if (w > balance) {

        cout << "Withdrawal failed! ";
        cout << w << " current balance is " << balance;
        cout << "\n You will be charged $15.00 for this. \n";
        balance -= 15.0;
    }
    else {
        BankAccount::withdraw(w);
    }
}
ServAndOwed CheckingAccount::monthlyProc() {
    serviceCharges += 5.0;
    serviceCharges += 0.1 * numOfWithdrawals;
    monthlyServiceCharges += serviceCharges;
    ServAndOwed temp;
    temp.servCharges = serviceCharges;
    BankAccount::monthlyProc();
    if (balance < 0) {
        owed = 0 - balance;
    }
    temp.totalOwed = owed;
    owed = 0;
    return temp;
}
