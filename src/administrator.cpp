#include "administrator.h"
#include "bank.h"
#include "investmentAccount.h"
#include "privateUser.h"
#include "savingsAccount.h"
#include "stock.h"
#include "transferAccount.h"
#include "user.h"

#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cstdlib>
#include <limits>

// Check if string contains a number
void ValidName(std::string word){
  char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

  // Loops throgh all the characters of the word
  for(char c : word){
    // Loops through all the numbers
    for(char n : numbers){
      // If the character is a number return true
      if(c == n){
        throw std::invalid_argument("Name contains numbers");
      }
    }
  }
}

// Check if the social security number is vaild
void ValidSocialSecurityNumber(std::string socialSecurityNumber){
  // Check if the social security number has the correct length
  if (socialSecurityNumber.length() != 10 && socialSecurityNumber.length() != 12){
    throw std::invalid_argument("Social security number is of invalid length");
  }

  int index = 0;

  std::string temp = "";
  // Loop through the chars in the year of the social security number and adds them to a temporary string
  while(index < socialSecurityNumber.length() - 8){
    temp += socialSecurityNumber[index];
    index++;
  }

  int year;

  // Convert the year to an int
  try {
    year = stoi(temp);
  }
  catch (std::invalid_argument e) {
    throw std::invalid_argument("Social security number contains non number");
  }

  // Set the temp to the characters of the month then move the index to days
  temp = "";
  temp += socialSecurityNumber[index];
  index++;
  temp += socialSecurityNumber[index];
  index++;

  int month;

  // Convert the mounth to an int
  try {
    month = stoi(temp);
  }
  catch (std::invalid_argument e) {
    throw std::invalid_argument("Social security number contains non number");
  }

  // Set the temp to the characters of the day
  temp = "";
  temp += socialSecurityNumber[index];
  index++;
  temp += socialSecurityNumber[index];
  index++;

  int day;

  // Convert the day to an int
  try {
    day = stoi(temp);
  }
  catch (std::invalid_argument e) {
    throw std::invalid_argument("Social security number contains non number");
  }

  // Check if the year has passed
  if(year > 2022){
    throw std::invalid_argument("Social security number contains invalid year");
  }

  // Check if the month is vaild
  if(month < 1 || month > 12){
    throw std::invalid_argument("Social security number contains invalid month");
  }

  // Check if the day is valid
  if(((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || ((month == 1 || month == 3 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) || (month == 2 && day > 29) || day < 1){
    throw std::invalid_argument("Social security number contains invalid day");
  }
}

// Constructor
Administrator::Administrator(std::string name, std::string socialSecurityNumber, std::string password, Bank *bank):User(name, socialSecurityNumber, password, bank){
  this->bank = bank;
}

// Function for the admin to interact with the bank
bool Administrator::Menu(){
  // Loop that run while the admin is logedin
  while (true) {
    int choice = 0;

    std::cout << std::endl;
    std::cout << "Menu" << std::endl;
    std::cout << "1: Create user" << std::endl;
    std::cout << "2: Show users" << std::endl;
    std::cout << "3: Create account" << std::endl;
    std::cout << "4: Link account" << std::endl;
    std::cout << "5: Deposit money" << std::endl;
    std::cout << "6: Show stocks" << std::endl;
    std::cout << "9: Logout" << std::endl;
    std::cout << "0: Exit" << std::endl;

    std::cin >> choice;

    system("clear"); // ADD platform agnotic
    
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
      case 5:
        DepositMoney(); // Deposit money into account
        break;
      case 6:
        ShowStocks();
        break;
      case 9:
        return true; // Logout but dont exit the program
      case 0:
        return false; // Exit the program
      default:
        std::cerr << "Invalind choice" << std::endl;
        break;
    }
  }
}

// Create a new user in the bank
void Administrator::CreateUser(){
  std::string name;
  std::string socialSecurityNumber;
  std::string password;

  bool admin;

  // Loop until the user has chosen if they are going to create an admin
  while (true) {
    std::string input;
    std::cout << "Are you createing an admin? (y/n)" << std::endl;
    std::cin >> input;

    if (input == "y") {
      admin = true;
      break;
    }
    else if (input == "n") {
      admin = false;
      break;
    }
    else {
      std::cerr << "Inccorect choice" << std::endl;
    }
  }

  // If the user is an admin use to same value for ssn and name and do not check ssn validity
  // Else enter ssn and name with checks
  if (admin) {
    std::cout << "Enter username: " << std::endl;
    std::cin >> socialSecurityNumber;

    name = socialSecurityNumber;
  }
  else {
    // Loop whiel the entered social security number is invalid
    while(true){
      std::cout << "Enter social security number: " << std::endl;
      std::cin >> socialSecurityNumber;

      try {
        ValidSocialSecurityNumber(socialSecurityNumber);
        break;
      }
      catch (std::invalid_argument e) {
        std::cerr << e.what() << std::endl;
      }
    }
    
    // Loop while the entered name is invalid
    while(true){
      std::cout << "Enter name: " << std::endl;
      std::cin >> name;

      try {
        ValidName(name);
        break;
      }
      catch (std::invalid_argument e) {
        std::cerr << e.what() << std::endl;
      }
    }
  }

  std::cout << "Enter password: " << std::endl;
  std::cin >> password;

  // If the user is an admin add the user to only the user list
  // Else add the user to both the user and customer lists
  if (admin) {
    Administrator* administrator = new Administrator(name, socialSecurityNumber, password, bank);
    
    bank->AddUser(administrator, nullptr);
  }
  else {
    PrivateUser* customer = new PrivateUser(name, socialSecurityNumber, password, bank);
    User* user = customer;

    bank->AddUser(user, customer);
  }
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

  int choice;

  std::cout << "1: Transaction account" << std::endl;
  std::cout << "2: Savings account" << std::endl;
  std::cout << "3: Investment account" << std::endl;

  std::cin >> choice;

  // Runs apropriate code based on the type of account that's being created
  switch (choice) {
    case 1: {
      float intrest;

      // Loop while the entered intrest rate is invalid
      while (true) {
        try {
          std::cout << "Enter current intrest rate: " << std::endl;
          std::cin >> intrest;
          break;
        }
        catch (std::ios_base::failure e) {
          std::cerr << "Invalid number" << std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
      }

      bank->AddAccount(new TransactionAccount(accountNumber, clearingNumber, intrest));
      break;
    }
    case 2: {
      float intrest;
      float maxWithdrawl;

      // Loop while the entered intrest is invalid
      while (true) {
        try {
          std::cout << "Enter current intrest rate: " << std::endl;
          std::cin >> intrest;
          break;
        }
        catch (std::ios_base::failure e) {
          std::cerr << "Invalid number" << std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
      }

      // Loop while the enterd amount is invalid
      while (true) {
        try {
          std::cout << "Enter maximum withdrawl amount: " << std::endl;
          std::cin >> maxWithdrawl;
          break;
        }
        catch (std::ios_base::failure e) {
          std::cerr << "Invalid number" << std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
      }

      bank->AddAccount(new SavingsAccount(accountNumber, clearingNumber, intrest, maxWithdrawl));
      break;
    }
    case 3: {
      float tax;

      // Loop while the entered tax is invalid
      while (true) {
        try {
          std::cout << "Enter current tax (as decimal): " << std::endl;
          std::cin >> tax;
          break;
        }
        catch (std::ios_base::failure e) {
          std::cerr << "Invalid number" << std::endl;
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
      }

      InvestmentAccount *account = new InvestmentAccount(accountNumber, clearingNumber, tax);

      bank->AddAccount(account);
      bank->AddInvestmentAccount(account);
      break;
    }
    default: {
      std::cout << "Invalind choice" << std::endl;
      break;
    }
  }

  std::string input;

  std::cout << "Do you wish to link the account? (y/n) " << std::endl;
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
void Administrator::LinkAccount() {
  std::vector<Account*> accounts = bank->GetAccounts();
  std::vector<InvestmentAccount*> investmentAccounts = bank->GetInvestmentAccounts();
  std::vector<PrivateUser*> customers = bank->GetCustomer();
  
  std::string socialSecurityNumber;
  std::string accountNumber;

  PrivateUser* customer;

  // Loop while the ssn does not match a user
  while (true) {
    std::cout << "Enter user's social security number: " << std::endl;
    std::cin >> socialSecurityNumber;

    // Loop through all customers and set the correct one as active
    for (long unsigned int i = 0; i < customers.size(); i++) {
      if (customers[i]->GetSocialSecurityNumber() == socialSecurityNumber) {
        customer = customers[i];
      }
    }

    if (customer == nullptr) {
      std::cerr << "Customer does not exist" << std::endl;
    }
    else {
      break;
    }
  }

  bool run = true;
  bool investment;
  std::string answer;

  while (true) {
    std::cout << "Is the account an investmentAccount (y/n): " << std::endl;
    std::cin >> answer;

    if (answer == "y") {
      investment = true;
      break;
    }
    else if (answer == "n") {
      investment = false;
      break;
    }
    else {
      std::cerr << "Invalid choice" << std::endl;
    }
  }

  // Loop while the account number does not match an account
  while (run) {
    std::cout << "Enter account number: " << std::endl;
    std::cin >> accountNumber;

    if (investment) {
      for (int i = 0; i < investmentAccounts.size(); i++) {
        if (investmentAccounts[i]->GetAccountNumber() == accountNumber) {
          customer->AddInvestmentAccount(investmentAccounts[i]);
          run = false;
          break;
        }
      }
    }

    // Loop through all the accounts and add the correct one to the active users list of accounts
    for (long unsigned int i = 0; i < accounts.size(); i++){
      if (accounts[i]->GetAccountNumber() == accountNumber) {
        customer->AddAccount(accounts[i]);
        run = false;
        break;
      }
    }

    if (!run) {
      break;
    }
    else {
      std::cerr << "Account does not exist" << std::endl;
    }
  }
}

// Add money to an account
void Administrator::DepositMoney() {
  Account* account;
  float amount;

  // Loop while the entered amount is invalid
  while (true) {
    std::string accountNumber;
    std::cout << "Enter account number: " << std::endl;
    std::cin >> accountNumber;

    std::vector<Account*> accounts = bank->GetAccounts();

    // Loop through all the accounts in the bank
    for (long unsigned int i = 0; i < accounts.size(); i++){
      if (accounts[i]->GetAccountNumber() == accountNumber) {
        account = accounts[i];
        break;
      }
    }

    if (account == nullptr) {
      std::cerr << "The account does not exist" << std::endl;
    }
    else {
      break;
    }
  }

  // Loop while the amount is invalid
  while (true) {
    try {
      std::cout << "Enter amount: " << std::endl;
      std::cin >> amount;
      break;
    }
    catch (std::ios_base::failure e) {
      std::cerr << "Invalid input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  account->ModifyBalance(amount);
}

// Add a new stock to the bank
void Administrator::AddStock() {
  std::string name;
  float numberOfStocks;
  float price;

  // Loop while the entered name is invalid
  while (true) {
    try {
      std::cout << "What is the name: " << std::endl;
      std::cin >> name;

      ValidName(name);
      break;
    }
    catch (std::invalid_argument e) {
      std::cerr << e.what() << std::endl;
    }
  }

  // Loop while the number of stocks entered is invalid
  while (true) {
    try {
      std::cout << "How many stocks are on sale: " << std::endl;
      std::cin >> numberOfStocks;
      break;
    }
    catch (std::ios_base::failure e) {
      std::cerr << "Invalid input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  // Loop while the price of the stock is invalid
  while (true) {
    try {
      std::cout << "What is the price per stock: " << std::endl;
      std::cin >> price;
      break;
    }
    catch (std::ios_base::failure e) {
      std::cerr << "Invalid input" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  bank->AddStock(new Stock(name, numberOfStocks, price));
}

void Administrator::ShowStocks() {
  std::vector<Stock*> stocks = bank->GetStocks();
  for (int i = 0; i < stocks.size(); i++) {
    std::cout << stocks[i]->GetName() << std::endl;
  }
}
