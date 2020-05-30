//
// Created by mohamed on 5/28/2020.
//

#ifndef PROGRAM305_OOPPROJECT_ACCOUNTOWNER_H
#define PROGRAM305_OOPPROJECT_ACCOUNTOWNER_H
#include <string>
using namespace  std;
class AccountOwner {
private:
    string firstName;
    string lastName;
    string phoneNUm;
    string ID;
    string userID;
    string password;

public:
    AccountOwner();
    AccountOwner( string &firstName,  string &lastName,  string &phoneNUm,  string &id);

     string getFirstName() const ;

    bool setFirstName(const string &firstName);

     string getLastName() const;

    bool setLastName(const string &lastName);

     string getPhoneNUm() const;

    bool setPhoneNUm(const string &phoneNUm);

      string getId() const;

    bool setId(const string &id);

     string getUserId() const;

    void setUserId(const string &userId);

     string getPassword() const;

    void setPassword(const string &password);

    virtual ~AccountOwner();

  };


#endif //PROGRAM305_OOPPROJECT_ACCOUNTOWNER_H
