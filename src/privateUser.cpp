#include "privateUser.h"
#include <string>
#include <iostream>

PrivateUser::PrivateUser(std::string name, std::string socialSecurityNumber, std::string password):User(name, password){
  this->socialSecurityNumber = socialSecurityNumber;
}

void PrivateUser::Menu(){
  std::cout << "Menu" << std::endl;
}
