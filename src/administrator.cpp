#include "administrator.h"
#include "bank.h"
#include <iostream>
#include <string>

Administrator::Administrator(std::string name, std::string password, Bank *bank):User(name, password){
  this->bank = bank;
}

void Administrator::Menu(){
  int choice = 0;

  std::cout << "Menu" << std::endl;
  std::cout << "1: Create user" << std::endl;

  std::cin >> choice;

  switch (choice) {
    case 1:
      CreateUser();
      break;
    default:
      std::cout << "Invalind choice" << std::endl;
  }
}

void Administrator::CreateUser(){
  std::string name;
  std::string socialSecurityNumber;
  std::string password;

  std::cout << "Enter name: " << std::endl;
  std::cin >> name;

  std::cout << "Enter social security number: " << std::endl;
  std::cin >> socialSecurityNumber;

  std::cout << "Enter password: " << std::endl;
  std::cin >> password;

   
  std::cin >> password;

   
}
