#include <string>
#include <iostream>
#include <vector>

#include "administrator.h"
#include "bank.h"
#include "privateUser.h"

Bank::Bank(std::string name){
  this->name = name;
  users.push_back(new Administrator("root", "root", "root", this));
}

void Bank::Login() {
  bool run = true;

  std::string name;
  std::string password;

  while (run) {
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    std::cout << "Enter password: " << std::endl;
    std::cin >> password;

    for (long unsigned int i = 0; i < users.size(); i++) {
      if (users[i]->GetName() == name && users[i]->CheckPassword(password)){
        run = users[i]->Menu();
        break;
      }
      else {
        std::cout << "Incorrect username or password" << std::endl;
      }
    }
  }
}

void Bank::AddUser(User *user, PrivateUser* customer){
  users.push_back(user);

  if (customer != nullptr){
    customers.push_back(customer);
  }
}
