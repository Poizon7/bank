#pragma once

#include <string>

class Account {
protected:
  float balance;
  std::string accountNumber;
  std::string clearingNumber;

public:
  Account(std::string accountNumber, std::string clearingNumber);
  virtual void ModifyBalance(float change) = 0;
  std::string GetAccountNumber(){return accountNumber;}
  float GetBalance(){return balance;}
};
