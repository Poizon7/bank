#pragma once

#include <string>

class Account {
protected:
  float balance; // Amount of money in the account
  std::string accountNumber; // Identifier for the account
  std::string clearingNumber; // ???

public:
  // Constructor
  Account(std::string accountNumber, std::string clearingNumber);

  // Setters and getters
  virtual void ModifyBalance(float change) = 0;
  std::string GetAccountNumber(){return accountNumber;}
  float GetBalance(){return balance;}
};
