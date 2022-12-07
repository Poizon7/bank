#pragma once

#include <string>
#include <vector>

#include "user.h"
#include "privateUser.h"
#include "account.h"

class Bank {
private:
  std::string name;
  std::vector<User*> users;
  std::vector<Account*> accounts;
  std::vector<PrivateUser*> customers;

public:
  Bank(std::string);
  void Login();
  void AddUser(User* user, PrivateUser* customer); 
  std::vector<User*> GetUsers(){return users;};
  std::vector<PrivateUser*> GetCustomer(){return customers;}
  void AddAccount(Account* account) {accounts.push_back(account);}
  std::vector<Account*> GetAccounts(){return accounts;}
};
