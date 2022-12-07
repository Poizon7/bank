#pragma once

#include "user.h"
#include "account.h"
#include <string>
#include <vector>

class PrivateUser : public User {
private:
  std::vector<Account*> accounts;

public:
  PrivateUser(std::string name, std::string socialSecurityNumber, std::string password);
  bool Menu() override;
  void ShowAccounts();
  void AddAccount(Account *account){accounts.push_back(account);}
};
