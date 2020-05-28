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

    virtual ~AccountOwner();

  };


#endif //PROGRAM305_OOPPROJECT_ACCOUNTOWNER_H
