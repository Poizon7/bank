#pragma once

#include "user.h"
#include "account.h"
#include <string>
#include <vector>

class PrivateUser : public User {
private:
  std::vector<Account*> accounts; // List of all the users accounts

private:
  void ShowAccounts(); // Show all the users accounts

public:
  // Constructors
  PrivateUser(std::string name, std::string socialSecurityNumber, std::string password);

  // Function for the user to interact with the bank
  bool Menu() override;

  // Setter and getter
  void AddAccount(Account *account){accounts.push_back(account);}
};
