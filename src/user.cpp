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

bool ContainsNumber(std::string word){
  char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  for(char c : word){
    for(char n : numbers){
      if(c == n){
        return true;
      }
    }
  }
  return false;
}
