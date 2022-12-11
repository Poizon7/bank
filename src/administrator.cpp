#include "administrator.h"
#include "bank.h"
#include "privateUser.h"
#include "transferAccount.h"
#include "user.h"

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

int stringTointeger(std::string str)
{
    int temp = 0;
    for (int i = 0; i < str.length(); i++) {
        temp = temp * 10 + (str[i] - '0');
    }
    return temp;
}

// Check if string contains a number
bool ValidName(std::string word){
  char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

  // Loops throgh all the characters of the word
  for(char c : word){
    // Lppos through all the numbers
    for(char n : numbers){
      // If the character is a number return true
      if(c == n){
        return false;
      }
    }
  }
  return true;
}

bool ValidSocialSecurityNumber(std::string socialSecurityNumber){
  // Check if the social security number has the correct length
  if (socialSecurityNumber.length() != 10 && socialSecurityNumber.length() != 12){
    return false;
  }

  int index = 0;

  std::string temp = "";
  // Loop through the chars in the year of the social security number and adds them to a temporary string
  while(index < socialSecurityNumber.length() - 8){
    temp += socialSecurityNumber[index];
    index++;
  }

  // Convert the year to an int
  int year = stringTointeger(temp);

  // Set the temp to the characters of the month then move the index to days
  temp = socialSecurityNumber[index] + socialSecurityNumber[index + 1];
  index += 2;

  // Convert the mounth to an int
  int month = stringTointeger(temp);

  // Set the temp to the characters of the day
  temp = socialSecurityNumber[index] + socialSecurityNumber[index + 1];

  // Convert the day to an int
  int day = stringTointeger(temp);

  // Check if the year has passed
  if(year > 2022){
    return false;
  }

  // Check if the month is vaild
  if(month < 1 || month > 12){
    return false;
  }

  // Check if the day is valid
  if(((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || ((month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || (month == 2 && day > 28) || day < 1){
    return false;
  }

  return true;
}

// Constructor
Administrator::Administrator(std::string name, std::string socialSecurityNumber, std::string password, Bank *bank):User(name, socialSecurityNumber, password){
  this->bank = bank;
}

// Function for the admin to interact with the bank
bool Administrator::Menu(){
  // Loop that run while the admin is logedin
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
    
    // Call the apropriate function based on the input from the user
    switch (choice) {
      case 1:
        CreateUser(); // Create a new user in the bank
        break;
      case 2:
        ShowUsers(); // Show all users in the bank
        break;
      case 3:
        CreateAccount(); // Create a new account in the bank
        break;
      case 4:
        LinkAccount(); // Link an account to a user
        break;
      case 9:
        return true; // Logout but dont exit the program
      case 0:
        return false; // Exit the program
      default:
        std::cout << "Invalind choice" << std::endl;
        break;
    }
  }
}

// Create a new user in the bank
// ADD ability to add admin
void Administrator::CreateUser(){
  std::string name;
  std::string socialSecurityNumber;
  std::string password;

  // Loop while the entered name is invalid
  while(true){
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    if(ValidName(name)){
      break;
    }
    else{
      std::cout << "Invalid name" << std::endl;
    }
  }

  // Loop while the entered social security number is invalid
  while(true){
    std::cout << "Enter social security number: " << std::endl;
    std::cin >> socialSecurityNumber;

    if(ValidSocialSecurityNumber(socialSecurityNumber)){
      break;
    }
    else {
      std::cout << "Invalid social security number" << std::endl;
    }
  }

  std::cout << "Enter password: " << std::endl;
  std::cin >> password;

  PrivateUser* customer = new PrivateUser(name, socialSecurityNumber, password);
  User* user = customer;

  bank->AddUser(user, customer);
}

// Shows all users in the bank
void Administrator::ShowUsers(){
  std::vector<User*> users = bank->GetUsers();

  // Loops through all the users and displays their name
  for (long unsigned int i = 0; i < users.size(); i++) {
    std::string name = users[i]->GetName();
    std::cout << name << std::endl;
  }
}

// Creates a new account
void Administrator::CreateAccount(){
  std::string accountNumber = std::to_string(rand());
  std::string clearingNumber = std::to_string(rand());

  int choice = 0;

  std::cout << "1: Transaction account" << std::endl;

  std::cin >> choice;

  // Runs apropriate code based on the type of account that's being created
  switch (choice) {
    case 1: {
      int intrest = 0;
      std::cout << "Enter current intrest rate: " << std::endl;
      std::cin >> intrest;
      bank->AddAccount(new TransactionAccount(accountNumber, clearingNumber, intrest));
      break;
    }
    default: {
      std::cout << "Invalind choice" << std::endl;
      break;
    }
  }

  std::string input = "";

  std::cout << "Do you wish to link the account: " << std::endl;

  std::cin >> input;

  // If the account is to be linked imedietly do so
  if (input == "y"){
    std::cout << accountNumber << std::endl;
    LinkAccount();
  }
  else {
    std::cout << accountNumber << std::endl;
  }
}

// Add an account to a users list of accounts
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

  // Loop through all customers and set the correct one as active
  for (long unsigned int i = 0; i < customers.size(); i++) {
    if (customers[i]->GetSocialSecurityNumber() == socialSecurityNumber) {
      customer = customers[i];
    }
  }

  // Loop through all the accounts and add the correct one to the active users list of accounts
  for (long unsigned int i = 0; i < accounts.size(); i++){
    if (accounts[i]->GetAccountNumber() == accountNumber) {
      customer->AddAccount(accounts[i]);
    }
  }
}
