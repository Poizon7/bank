#pragma once

#include "user.h"
#include <string>

class PrivateUser : public User {
private:
  std::string socialSecurityNumber;
  // std::vector<Account*> accounts;

public:
  PrivateUser(std::string name, std::string socialSecurityNumber, std::string password);
  void Menu() override;
};
