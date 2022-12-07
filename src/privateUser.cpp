#include "privateUser.h"
#include <string>
#include <iostream>

PrivateUser::PrivateUser(std::string name, std::string socialSecurityNumber, std::string password):User(name, socialSecurityNumber, password){}

bool PrivateUser::Menu(){
  int choice = 0;
  
  while (true) {
    std::cout << "Menu" << std::endl;
    std::cout << "Show accounts" << std::endl;

    std::cin >> choice;

    switch (choice) {
      case 1:
        ShowAccounts();
        break;
      case 9:
        return true;
      case 0:
        return false;
    }
  }
}

void PrivateUser::ShowAccounts(){
  for (long unsigned int i = 0; i < accounts.size(); i++){
    std::cout << accounts[i]->GetAccountNumber() << std::endl;
    std::cout << accounts[i]->GetBalance() << std::endl;
    std::cout << std::endl;
  }
}
