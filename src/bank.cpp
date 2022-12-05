#include <string>
#include <iostream>

#include "administrator.h"
#include "bank.h"

Bank::Bank(std::string name){
  this->name = name;
  users.push_back(new Administrator("root", "root", this));
}

void Bank::Login() {
  std::string name;
  std::string password;
  while (true) {
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    std::cout << "Enter password: " << std::endl;
    std::cin >> password;

    for (long unsigned int i = 0; i < users.size(); i++) {
      if (users[i]->GetName() == name && users[i]->CheckPassword(password)){
        users[i]->Menu();
        break;
      }
      else {
        std::cout << "Incorrect username or password" << std::endl;
      }
    }
  }
}
