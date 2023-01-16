#include "bank.h"
#include "privateUser.h"
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
    std::cout << "9: Logout" << std::endl;
    std::cout << "0: Exit" << std::endl;

    std::cin >> choice;

    // Calls the correct function based on the users input
    switch (choice) {
      case 1:
        ShowAccounts(); // Show all the users accounts
        break;
      case 9:
        return true; // Logout but don't quit the program
      case 0:
        return false; // Exit the program
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

void PrivateUser::SendMoney() {
  std::string accountNumber;

  std::cout << "From account: " << std::endl;
  std::cin >> accountNumber;

  Account* fromAccount;
  
  for (int i = 0; i < accounts.size(); i++) {
    if (accounts[i]->GetAccountNumber() == accountNumber) {
      fromAccount = accounts[i];
    }
  }

  std::cout << "To account: " << std::endl;
  std::cin >> accountNumber;

  
}
