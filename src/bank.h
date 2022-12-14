#pragma once

#include <string>
#include <vector>

#include "user.h"
#include "privateUser.h"
#include "account.h"

class Bank {
private:
  std::string name; // The banks name
  std::vector<User*> users; // All users in the bank
  std::vector<PrivateUser*> customers; // Only private users (PrivateUsers)
  std::vector<Account*> accounts; // All accounts

public:
  // Constructors
  Bank(std::string);

  // Function run from main to interact with the bank
  void Login();

  // Seters and geters
  void AddUser(User* user, PrivateUser* customer); 
  std::vector<User*> GetUsers(){return users;};
  std::vector<PrivateUser*> GetCustomer(){return customers;}

  void AddAccount(Account* account) {accounts.push_back(account);}
  std::vector<Account*> GetAccounts(){return accounts;}
};
