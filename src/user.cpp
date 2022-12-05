#include <iostream>
#include <ostream>
#include <string>

#include "user.h"

User::User(std::string name, std::string password){
  this->name = name;
  this->password = password;
}

bool User::CheckPassword(std::string password){
  if (this->password == password) {
    return true;
  }
  else {
    return false;
  }
}
