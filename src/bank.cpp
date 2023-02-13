#include <algorithm>
#include <sstream>
#include <stdexcept>
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


  try {
    std::ifstream fin("stocks.txt");

    // Loop for each stock in the file
    for (std::string line; std::getline(fin, line); ) {
      std::vector<std::string> variables;
      std::string variable;

      std::istringstream iss(line);

      // Loop for each cvs
      while (std::getline(iss, variable, ',')) {
        variables.push_back(variable);
      }

      try {
        AddStock(new Stock(variables[0], std::stof(variables[1]), std::stof(variables[2])));
      }
      catch (std::invalid_argument e) {
        std::cerr << "stock file contains invalid stocks" << std::endl;
      }
    }

    fin.close();
  }
  catch (std::ifstream::failure e) {
    std::cerr << "Exception opening/reading/closing the stock file" << std::endl;
  }
}

// Record the stock to the file and clear memory
void Bank::Close() {
  std::ofstream fout;

  try {
    fout.open("stocks.txt");

    // Loop through all the stocks, write them to the file and then release the memory
    for (int i = 0; i < stocks.size(); i++) {
      fout << stocks[i]->GetName() << "," << stocks[i]->GetNumberOfStocks() << "," << stocks[i]->GetPrice() << "\n";
      delete stocks[i];
    }

    fout.close();
  }
  catch (std::ifstream::failure e) {
    std::cerr << "Exceprion opening/reading/closing the stock file" << std::endl;
  }

  // Release the memory for all the accounts
  for (int i = 0; i < accounts.size(); i++) {
    delete accounts[i];
  }

  // Realease the memory for all the users
  for (int i = 0; i < users.size(); i++) {
    delete users[i];
  }
}

// The main way of interacting with the bank
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

    // system("clear");
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
      std::cerr << "Incorrect username or password" << std::endl;
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

// Send money to a different account in the bank
void Bank::SendMoney(std::string accountNumber, float amount) {
  if (amount < 0) {throw std::invalid_argument("Cannot send less then 0");}

  bool success = false;

  for (int i = 0; i < accounts.size(); i++) {
    if (accounts[i]->GetAccountNumber() == accountNumber) {
      accounts[i]->ModifyBalance(amount);
      success = true;
      break;
    }
  }

  if (!success) {
    throw std::invalid_argument("Account does not exist");
  }
}
