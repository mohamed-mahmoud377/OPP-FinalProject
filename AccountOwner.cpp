//
// Created by mohamed on 5/28/2020.
//

#include "AccountOwner.h"
#include <cstring>
#include <cctype>
#include <string>
using namespace std;
AccountOwner::AccountOwner() {

    firstName = "none";
    lastName= "none";
    phoneNUm = "none";
    ID = "none";
    userID= "none";
    password="none";
}

AccountOwner::AccountOwner( string &firstName,  string &lastName,  string &phoneNUm,  string &id)
        : firstName(firstName), lastName(lastName), phoneNUm(phoneNUm), ID(id) {

}

 string AccountOwner::getFirstName() const {
    return firstName;
}

bool AccountOwner::setFirstName(const string &firstName) {
    for(char i : firstName){
        if(isdigit(i) || !isprint(i))
            return false;
    }
    this->firstName= firstName;
    return true;
}

 string AccountOwner::getLastName() const {
    return lastName;
}

bool AccountOwner::setLastName(const string &lastName) {
    for(auto const &i : firstName){
        if(isdigit(i) || !isprint(i))
            return false;
    }
    this->lastName= lastName;
    return true;

}

 string AccountOwner::getPhoneNUm() const {
    return phoneNUm;
}

bool AccountOwner::setPhoneNUm(const string &phoneNUm) {
    if(phoneNUm.size()!=11){
        return false;
    }
    for(auto const &i: phoneNUm){
        if(!isdigit(i))
            return false;
    }
    this->phoneNUm= phoneNUm;
    return true;
}

 string AccountOwner::getId() const {
    return ID;
}

bool AccountOwner::setId(const string &id) {
  if(id.size()!=14){
      return false;
  }
    for(auto const &i: phoneNUm){
        if(!isdigit(i))
            return false;
    }
    this->ID= id;
    return true;

}

 string AccountOwner::getUserId() const {
    return userID;
}

void AccountOwner::setUserId(const string &userId) {
    userID = userId;
}

 string AccountOwner::getPassword() const {
    return password;
}

void AccountOwner::setPassword(const string &password) {
    AccountOwner::password = password;
}

AccountOwner::~AccountOwner() = default;
