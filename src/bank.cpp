#include <sstream>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "administrator.h"
#include "bank.h"
#include "privateUser.h"
#include "stock.h"

// Basic constructor that sets the banks name
Bank::Bank(std::string name){
  this->name = name;
  users.push_back(new Administrator("root", "root", "root", this)); // Add an admin to the bank

  std::ifstream fin;
  std::string line;
  fin.open("stocks");

  // Loop for each stock in the file
  while (std::getline(fin, line)) {
    std::vector<std::string> variables;
    std::string variable;

    std::istringstream iss(line);

    // Loop for each cvs
    while (std::getline(iss, variable, ',')) {
      variables.push_back(variable);
    }

    Stock* stock = new Stock(variables[0], std::stof(variables[1]), std::stof(variables[2]));
  }

  fin.close();
}

Bank::~Bank(){
  std::ofstream fout;

  fout.open("stocks");

  for (int i = 0; i < stocks.size(); i++) {
    fout << stocks[i]->GetName() << "," << stocks[i]->GetNumberOfStocks() << "," << stocks[i] << "\n";
    delete stocks[i];
  }

  fout.close();
}

void Bank::Close() {
  for (int i = 0; i < accounts.size(); i++) {
    delete accounts[i];
  }

  for (int i = 0; i < users.size(); i++) {
    delete users[i];
  }
}

void Bank::Login() {
  bool run = true;

  std::string socialSecurityNumber;
  std::string password;

  system("clear");

  // Loop that runs while the program is active
  while (run) {
    std::cout << "Enter social security number: " << std::endl;
    std::cin >> socialSecurityNumber;

    std::cout << "Enter password: " << std::endl;
    std::cin >> password;

    system("clear");
    User* user = nullptr;

    // Loops through all users and checks if the supplied name and password match a user
    for (long unsigned int i = 0; i < users.size(); i++) {
      // If name and password match then give the user access to their account
      if (users[i]->GetSocialSecurityNumber() == socialSecurityNumber && users[i]->CheckPassword(password)){
        user = users[i];
        break;
      }
    }

    if (user == nullptr) {
      std::cout << "Incorrect username or password" << std::endl;
    } else {
      run = user->Menu();
    }
  }
}

// Adds a user to the bank
void Bank::AddUser(User *user, PrivateUser* customer){
  users.push_back(user);

  // If the user is a customer add it to that list as well
  if (customer != nullptr){
    customers.push_back(customer);
  }
}

bool Bank::SendMoney(std::string accountNumber, float amount) {
  if (amount < 0) {return false;}

  for (int i = 0; i < accounts.size(); i++) {
    if (accounts[i]->GetAccountNumber() == accountNumber) {
      accounts[i]->ModifyBalance(amount);
      return true;
    }
  }

  return false;
}
