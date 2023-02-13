#include "account.h"
#include "bank.h"
#include "privateUser.h"
#include <ios>
#include <limits>
#include <stdexcept>
#include <string>
#include <iostream>

// Constructor
PrivateUser::PrivateUser(std::string name, std::string socialSecurityNumber, std::string password, Bank* bank):User(name, socialSecurityNumber, password, bank){}

// Function for the user to interact with the bank
bool PrivateUser::Menu(){
  int choice = 0;
  
  // Loops for as long as the user is logedin
  while (true) {
    std::cout << "Menu" << std::endl;
    std::cout << "1: Show accounts" << std::endl;
    std::cout << "2: Send money" << std::endl;
    std::cout << "3: Trade stocks" << std::endl;
    std::cout << "4: Show stocks" << std::endl;
    std::cout << "9: Logout" << std::endl;
    std::cout << "0: Exit" << std::endl;

    std::cin >> choice;

    // Calls the correct function based on the users input
    switch (choice) {
      case 1:
        ShowAccounts(); // Show all the users accounts
        break;
      case 2:
        SendMoney(); // Send monet to a different account
        break;
      case 3:
        TradeStocks();
        break;
      case 4:
        ShowStocks();
        break;
      case 9:
        return true; // Logout but don't quit the program
      case 0:
        return false; // Exit the program
      default:
        std::cerr << "Invalid choice" << std::endl;
        break;
    }
  }
}

// Show all the users accounts
void PrivateUser::ShowAccounts(){
  // Loops through all the users accounts and displays their account number and balance
  for (long unsigned int i = 0; i < accounts.size(); i++){
    std::cout << accounts[i]->GetAccountNumber() << std::endl;
    std::cout << "Balance: " << accounts[i]->GetBalance() << std::endl;
    std::cout << std::endl;
  }
}

// Send money to a different account
void PrivateUser::SendMoney() {
  std::string accountNumber;
  float amount;
  Account* fromAccount;

  // Loop while the entered account number is does not exist
  while (true) {
    std::cout << "From account: " << std::endl;
    std::cin >> accountNumber;
    
    for (int i = 0; i < accounts.size(); i++) {
      if (accounts[i]->GetAccountNumber() == accountNumber) {
        fromAccount = accounts[i];
        break;
      }
    }

    if (fromAccount == nullptr) {
      std::cerr << "Account does not exist" << std::endl;
    }
    else {
      break;
    }
  }

  while (true) {
    try {
      std::cout << "How much to send: " << std::endl;
      std::cin >> amount;

      if (amount > fromAccount->GetBalance()) {
        std::cerr << "You are trying to send more money than you have" << std::endl;
      }
      else {
        break;
      }
    }
    catch (std::ios_base::failure e) {
      std::cerr << "Invalid input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  while (true) {
    bool run = true;
    
    std::cout << "To account: " << std::endl;
    std::cin >> accountNumber;

    std::vector<Account*> accounts = bank->GetAccounts();

    for (int i = 0; i < accounts.size(); i++) {
      if (accountNumber == accounts[i]->GetAccountNumber()) {
        run = false;
        break;
      }
    }

    if (run) {
      std::cerr << "The account does not exist" << std::endl;
    }
    else {
      break;
    }
  }

  while (true) {
    try {
      bank->SendMoney(accountNumber, amount);
      std::cout << "Money sent" << std::endl;
      fromAccount->ModifyBalance(amount * -1);
      break;
    }
    catch (std::invalid_argument e) {
      std::cerr << e.what() << std::endl;

      std::string answer;

      std::cout << "Do you wish to try again (y/n)" << std::endl;
      std::cin >> answer;

      if (answer != "y") {
        break;
      }
    }
  }
}

void PrivateUser::TradeStocks() {
  std::string accountNumber;

  bool success = false;

  while (true) {
    std::cout << "Which account to trade from: " << std::endl;
    std::cin >> accountNumber;

    for (int i = 0; i < investmentAccounts.size(); i++) {
      if (investmentAccounts[i]->GetAccountNumber() == accountNumber) {
        investmentAccounts[i]->ModifyStocks(bank);
        success = true;
        break;
      }
    }

    if (success) {
      break;
    }
    else {
      std::cout << "Account does not exist" << std::endl;
    }
  }
}

void PrivateUser::ShowStocks() {
  for (int i = 0; i < investmentAccounts.size(); i++) {
    std::unordered_map<std::string, float> stocks = investmentAccounts[i]->GetStocks();

    for (auto [key, value] : stocks) {
      std::cout << key << ": " << value << std::endl;
    }
  }
}
