//
// Created by mohamed on 5/30/2020.
//

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount():isActive{Active} {
    type = "Saving";
}


bool SavingsAccount::withdraw(double withdraw) {
   // A function that checks to see if the account is inactive before a withdrawal is made.
    //(No withdrawal will be allowed if the account is not active.)
    //A withdrawal is then made by calling the base class version of the function.




}

bool SavingsAccount::deposit(double deposit) {
//     A function that checks to see if the account is inactive before a deposit is made.
//     If the account is inactive and the deposit brings the balance above $25,
//     the account becomes active again. The deposit is then made by calling the base class version of the function.
    if(balance+deposit>=25)
        isActive=Active;
    else
        isActive =Inactive;

  if(isActive==Inactive)
      return false;
    return BankAccount::deposit(deposit);
}

void SavingsAccount::monthlyPro() {
// : Before the base class function is called,
// this function checks the number of withdrawals. If the number of withdrawals for the month is more than 4,
// a service charge of $1 for each withdrawal above 4 is added to the base class variable that holds the monthly service charges.
// (Don’t forget to check the account balance after the service charge is taken.
//If the balance falls below $25, the account becomes inactive.)






}

SavingsAccount::~SavingsAccount() {

}



