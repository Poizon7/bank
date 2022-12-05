#include "administrator.h"
#include "bank.h"
#include "privateUser.h"
#include "user.h"

#include <iostream>
#include <string>
#include <vector>

Administrator::Administrator(std::string name, std::string password, Bank *bank):User(name, password){
  this->bank = bank;
}

void Administrator::Menu(){
  while (true) {
    int choice = 0;

    std::cout << "Menu" << std::endl;
    std::cout << "1: Create user" << std::endl;
    std::cout << "2: Show users" << std::endl;

    std::cin >> choice;

    switch (choice) {
      case 1:
        CreateUser();
        break;
      case 2:
        ShowUsers();
        break;
      default:
        std::cout << "Invalind choice" << std::endl;
    }
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

  User* user = new PrivateUser(name, socialSecurityNumber, password);
  bank->AddUser(user);
}


void Administrator::ShowUsers(){
  std::vector<User*> users = bank->GetUsers();

  for (int i = 0; i < users.size(); i++) {
    std::string name = users[i]->GetName();
    std::cout << name << std::endl;
  }
}
