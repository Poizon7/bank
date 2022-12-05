#pragma once

#include <string>

#include "user.h"
#include "bank.h"

class Administrator : public User {
private:
  Bank *bank;

private:
  void CreateUser();
  void CreateAccount();
  void LinkAccount();
  void ShowUsers();

public:
  Administrator(std::string name, std::string password, Bank *bank);
  void Menu() override;
};
