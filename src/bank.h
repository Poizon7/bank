#pragma once

#include <string>
#include <vector>

#include "user.h"

class Bank {
private:
  std::string name;
  std::vector<User*> users;
  // std::vector<Account> accounts;

public:
  Bank(std::string);
  void Login();
};
