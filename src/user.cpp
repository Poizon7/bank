#include <iostream>
#include <ostream>
#include <string>

#include "user.h"

// Constructor the sets the neccesary variables
User::User(std::string name, std::string socialSecurityNumber, std::string password){
  this->name = name;
  this->socialSecurityNumber = socialSecurityNumber;
  this->password = password;
}

// Function that checks if the supplied password matches the users password
bool User::CheckPassword(std::string password){
  if (this->password == password) {
    return true;
  }
  else {
    return false;
  }
}
