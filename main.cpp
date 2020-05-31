#include <iostream>
#include <unistd.h>
#include "BankAccount.h"
#include "AccountOwner.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <vector>
BankAccount * getAccountByID(const vector<BankAccount *>& accounts,const string &ID){
    for(auto i : accounts){
        if(i->getAccountOwner()->getUserId()==ID){
            return i;
        }
    }
    return nullptr;
}
bool logInCheck(const string &ID ,const string &password ,const vector<BankAccount *>& accounts ){
    for(auto i : accounts){
        if(i->getAccountOwner()->getUserId()==ID){
            if(i->getAccountOwner()->getPassword()==password){
                return true;
            }
        }
    }
    return  false;
}
void loadHardCodedData( vector<BankAccount*>& accounts){
    auto* saving1 = new SavingsAccount;
    saving1->getAccountOwner()->setUserId("jerry");
    saving1->getAccountOwner()->setPassword("jerry");
    saving1->getAccountOwner()->setFirstName("jerry");
    saving1->setBalance(10);
    saving1->setStartingBalance(10);
    saving1->setAnnualInterestRate(.14);


    accounts.push_back(saving1);

    auto *saving2 = new SavingsAccount;
    saving2->getAccountOwner()->setUserId("shrief");
    saving2->getAccountOwner()->setPassword("shrief");
    saving2->getAccountOwner()->setFirstName("shrief");

    accounts.push_back(saving2);

    auto* checking1 = new CheckingAccount;
    checking1->getAccountOwner()->setUserId("dabos");
    checking1->getAccountOwner()->setPassword("dabos");
    checking1->getAccountOwner()->setFirstName("dabos");

    accounts.push_back(checking1);

    auto *checking2 = new CheckingAccount;
    checking2->getAccountOwner()->setUserId("amira");
    checking2->getAccountOwner()->setPassword("amira");
    checking2->getAccountOwner()->setFirstName("amira");
    checking2->setBalance(1000);
    checking2->setStartingBalance(1000);
    checking2->setAnnualInterestRate(.14);




    accounts.push_back(checking2);



    accounts.push_back(saving2);
}
bool checkUserID(const string& ID,const vector<BankAccount*>& accounts){
    for(auto const &i : accounts){
        if(i->getAccountOwner()->getUserId()==ID)
            return false;
    }
    return true;

}
BankAccount*singUp(const vector<BankAccount *>& accounts){
     BankAccount *currentUser = nullptr;
    string string_input;
    double int_input;
    wrongInput:
    cout<<"what king of account do you want ?\n"<<endl;
    cout<<"[1] Saving account "<<endl;
    cout<<"[2] Checking account"<<endl;
    cin>>string_input;
    if(string_input=="1"){

        currentUser= new SavingsAccount;

    }else if(string_input=="2"){

        currentUser = new CheckingAccount;

    }else {
        cout << "wrong input" << endl;
        goto wrongInput;
    }

//    auto* savingsAccount = new SavingsAccount{};
    cout<<"enter you first name : "<<endl;
    cin>>string_input;
    while(!currentUser->getAccountOwner()->setFirstName(string_input)){
        cerr<<"the name is not right only english char works"<<endl;
        cin>>string_input;
    }
    cout<<"enter you second name : "<<endl;
    cin>>string_input;
    while(!currentUser->getAccountOwner()->setLastName(string_input)){
        cerr<<"the name is not right only english char works"<<endl;
        cin>>string_input;
    }


    cout << "enter you ID (you are gonna use it to log in it )" << endl;
    cin>>string_input;
    while(!checkUserID(string_input,accounts)){
        cerr<<"the ID you entered is already taken "<<endl;
        cin>>string_input;
    }
    string ID = string_input;
    currentUser->getAccountOwner()->setUserId(string_input);
    string passWord;
    cout<<"enter you password : "<<endl;
    cin>>string_input;
    passWord=string_input;
    cout<<"confirm password :"<<endl;
    cin>>string_input;
    while(string_input!=passWord){
        cerr<<"the the confirmation password is wrong plz enter the password again : "<<endl;
        cin>>passWord;
        cout<<"confirm password :"<<endl;
        cin>>string_input;

    }
    currentUser->getAccountOwner()->setPassword(string_input);
    cout<<"enter your annual Interest Rate"<<endl;
    cin>>int_input;
    while(!currentUser->setAnnualInterestRate(int_input)){
        cout<<"the annual interest rate is not right only between (0-1)"<<endl;
        cin>>int_input;
    }
    cout<<"enter your national ID (14 digits) :"<<endl;
    cin>>string_input;
    while(!currentUser->getAccountOwner()->setId(string_input)){
        cerr<<"plz enter a correct national ID :"<<endl;
        cin>>string_input;
    }
    cout<<"enter your phone number : "<<endl;
    cin>>string_input;
    while(!currentUser->getAccountOwner()->setPhoneNUm(string_input)){
        cout<<"plz enter a correct phone number :"<<endl;
        cin>>string_input;
    }
    cout<<"you have created your profile successfully ! \n"<<endl;
    cout<<"you ID is : "<<ID<<endl;
    cout<<"your password : "<<passWord<<"\n\n"<<endl;
    sleep(5);
    cout<<"how much money to deposit "<<endl;

    cin>>int_input;
    while(!currentUser->setBalance(int_input)){
        if(!cin){
            cerr<<"enter a integer value !"<<endl;
            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout<<"you entered a wrong value "<<endl;
        cin>>int_input;

    }
    currentUser->setStartingBalance(int_input);



    return currentUser;



}

int main() {
    vector<BankAccount *> accounts {};
    BankAccount *currentUser= nullptr;
    loadHardCodedData(accounts);
    bool exit= false;
while(!exit) {
    while (true) {
        try {
            cout << "welcome to our Bank Account Management System \n" << endl;
            cout << "[1]Lon in" << endl;
            cout << "[2]sign up for a brand new account !\n" << endl;
            cout << "[3] exit" << endl;

            string string_input;
            double int_input;
            cin >> string_input;


            if (string_input == "1") {
                cout << "enter ID : " << endl;
                string id;
                cin >> id;
                cout << "enter password : " << endl;
                string password;
                cin >> password;
                while (!logInCheck(id, password, accounts)) {
                    cout << "the ID or password is wrong .. " << endl;
                    cout << "enter ID : " << endl;
                    cin >> id;
                    cout << "enter password : " << endl;
                    cin >> password;
                }
                currentUser = getAccountByID(accounts, id);


            } else if (string_input == "2") {

                currentUser = singUp(accounts);

            } else if (string_input == "3") {
                cout << "good bye :)" << endl;
                exit= true;
                break;
            } else {
                cout << "you entered a wrong input .." << endl;
                continue;
            }

            break;

        } catch (int &e) {
            cout << "exception is caught" << endl;
        }
    }
    if(currentUser->getType()=="Checking"){
        currentUser->setMonthlyServiceCharges(5);
    }
    while (true) {

        cout<<"welcome , "<< currentUser->getAccountOwner()->getFirstName()<<endl;
        cout<<"your account type : "<<currentUser->getType()<<"\n\n"<<endl;
        cout<<"[1] show balance "<<endl;
        cout<<"[2] Deposit "<<endl;
        cout<<"[3] WithDraw "<<endl;
        cout<<"[4] Apply monthly fees and interest "<<endl;
        cout<<"[5] Display month statistics"<<endl;
        cout<<"[6] Logout"<<endl;
        cout<<"[7] exit"<<endl;
        string string_input;
        double int_input;
        cin>>string_input;
        if(string_input=="1"){
            cout<<"your current balance : " <<currentUser->getBalance()<<endl;
            sleep(3);

        }else if(string_input=="2"){
            cout<<"how much money to deposit "<<endl;

            cin>>int_input;
            while(!currentUser->deposit(int_input)){
                if(!cin){
                    cerr<<"enter a integer value !"<<endl;
                    cin.clear();

                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                cout<<"you entered a wrong value "<<endl;
                cin>>int_input;

            }
            cout<<"transferring money ..."<<endl;
            sleep(3);
            cout<<"money deposited successfully"<<endl;
            cout<<"your current balance is "<<currentUser->getBalance()<<endl;
            sleep(3);





        }else if(string_input=="3"){
            cout<<"how much money to withdraw ?"<<endl;
            wronginput :
            cin>>int_input;
            if(!cin){
                cerr<<"enter a integer value !"<<endl;
                cin.clear();

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                goto wronginput;
            }
            int check =0;
            while(!currentUser->withdraw(int_input)){

                if(currentUser->getType()=="Saving"){
                    cout<<"sorry your account is inactive or you dont have enough money for this withdraw\n"<<endl;
                }else if(currentUser->getType()=="Checking"){
                    cout<<" sorry there isn’t enough in the account to pay the service charge\n"<<endl;
                }
                cout<<"want to try again (y/n)?"<<endl;
                cin>>string_input;
                if(string_input=="y"){
                    cout<<"how much money to withdraw ?"<<endl;
                    cin>>int_input;

                }else {
                    check=1;
                    break;
                }
            }
            if(check==0) {
                cout << "transferring money ..." << endl;
                sleep(3);
                cout << "money withdraw has been done successfully" << endl;
                cout << "your current balance is " << currentUser->getBalance() << endl;
                sleep(3);


            }
            check=0;
        }else if(string_input=="4"){
            currentUser->monthlyPro();
            cout<<"your monthly services : "<<currentUser->getMonthlyServiceCharges()<<endl;
            currentUser->setMonthlyInterestRate();
            cout<<"your monthly interest rate :"<<currentUser->getAnnualInterestRate()<<endl;
            cout<<"applying monthly fees"<<endl;
            currentUser->setMonthlyServiceCharges(0);
            sleep(2);
            cout<<"your balance now after applying fees and interest is  "<<currentUser->getBalance()<<endl;


        }else if(string_input=="5"){
            currentUser->displayMonthStatistics();
            sleep(6);


        }else if(string_input=="6"){
            break;

        }else if(string_input=="7"){
            exit = true;
            break;
        }else {
            cerr<<"wrong input"<<endl;

        }




    }


}
    return 0;
}
