#pragma once

#include <string>

class Bank;

class User {
private:
  std::string name;
  std::string socialSecurityNumber;
  std::string password;

protected:
  Bank* bank;

public:
  // Constructors
  User(std::string name, std::string socialSecurityNumber, std::string password, Bank* bank);

  // Function for interacting with the account
  virtual bool Menu() = 0;

  // Checking if the password matches the supplied one
  bool CheckPassword(std::string password);

  // Setters and getters
  std::string GetName(){ return name; }
  std::string GetSocialSecurityNumber(){return socialSecurityNumber;}
};
