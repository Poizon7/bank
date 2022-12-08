#include "privateUser.h"
#include <string>
#include <iostream>

// Constructor
PrivateUser::PrivateUser(std::string name, std::string socialSecurityNumber, std::string password):User(name, socialSecurityNumber, password){}

// Function for the user to interact with the bank
bool PrivateUser::Menu(){
  int choice = 0;
  
  // Loops for as long as the user is logedin
  while (true) {
    std::cout << "Menu" << std::endl;
    std::cout << "Show accounts" << std::endl;

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
    std::cout << accounts[i]->GetBalance() << std::endl;
    std::cout << std::endl;
  }
}
