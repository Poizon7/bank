#pragma once

#include <string>

#include "user.h"

class Administrator : public User {
private:
  void CreateUser(); // Creates a user and adds it to the list in the bank
  void CreateAccount(); // Creates an account and adds it to the list in the bank
  void LinkAccount(); // Adds an account to a users list of accounts
  void ShowUsers(); // Displays a list of all users in the bank
  void DepositNumber();

public:
  // Constructor that creates an admin user (only difference from a normal user is the bank*)
  Administrator(std::string name, std::string socialSecurityNumber, std::string password, Bank *bank);

  // Function for the admin to interact with the bank
  bool Menu() override;
};
