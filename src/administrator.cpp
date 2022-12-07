#include "administrator.h"
#include "bank.h"
#include "privateUser.h"
#include "transferAccount.h"
#include "user.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

Administrator::Administrator(std::string name, std::string socialSecurityNumber, std::string password, Bank *bank):User(name, socialSecurityNumber, password){
  this->bank = bank;
}

bool Administrator::Menu(){
  while (true) {
    int choice = 0;

    std::cout << "Menu" << std::endl;
    std::cout << "1: Create user" << std::endl;
    std::cout << "2: Show users" << std::endl;
    std::cout << "3: Create account" << std::endl;
    std::cout << "4: Link account" << std::endl;
    std::cout << "9: Logout" << std::endl;
    std::cout << "0: Exit" << std::endl;

    std::cin >> choice;

    switch (choice) {
      case 1:
        CreateUser();
        break;
      case 2:
        ShowUsers();
        break;
      case 3:
        CreateAccount();
        break;
      case 4:
        LinkAccount();
        break;
      case 9:
        return true;
      case 0:
        return false;
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

  PrivateUser* customer = new PrivateUser(name, socialSecurityNumber, password);
  User* user = customer;

  bank->AddUser(user, customer);
}


void Administrator::ShowUsers(){
  std::vector<User*> users = bank->GetUsers();

  for (long unsigned int i = 0; i < users.size(); i++) {
    std::string name = users[i]->GetName();
    std::cout << name << std::endl;
  }
}

void Administrator::CreateAccount(){
  std::string accountNumber = std::to_string(rand());
  std::string clearingNumber = std::to_string(rand());

  int choice = 0;

  std::cout << "1: Transaction account" << std::endl;

  std::cin >> choice;

  switch (choice) {
    case 1:
      int intrest = 0;
      std::cout << "Enter current intrest rate: " << std::endl;
      std::cin >> intrest;
      bank->AddAccount(new TransactionAccount(accountNumber, clearingNumber, intrest));
      break;
  }

  std::string input = "";

  std::cout << "Do you wish to link the account: " << std::endl;

  std::cin >> input;

  if (input == "y"){
    std::cout << accountNumber << std::endl;
    LinkAccount();
  }
  else {
    std::cout << accountNumber << std::endl;
  }
}

void Administrator::LinkAccount(){
  std::vector<Account*> accounts = bank->GetAccounts();
  std::vector<PrivateUser*> customers = bank->GetCustomer();
  
  std::string socialSecurityNumber = "";
  std::string accountNumber = "";

  std::cout << "Enter users social security number: " << std::endl;

  std::cin >> socialSecurityNumber;

  std::cout << "Enter account number: " << std::endl;

  std::cin >> accountNumber;

  PrivateUser* customer;

  for (long unsigned int i = 0; i < customers.size(); i++) {
    if (customers[i]->GetSocialSecurityNumber() == socialSecurityNumber) {
      customer = customers[i];
    }
  }

  for (long unsigned int i = 0; i < accounts.size(); i++){
    if (accounts[i]->GetAccountNumber() == accountNumber) {
      customer->AddAccount(accounts[i]);
    }
  }
}
