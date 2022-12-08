#pragma once

#include "account.h"
#include <string>

class BankAccount : public Account {
protected:
  float intrest; // The intrestrate of the account

public:
  // Constructor
  BankAccount(std::string accountNumber, std::string clearingNumber, float intrest);

  // Setters and getters
  virtual void ModifyBalance(float change) = 0;
  float GetIntrest(){return intrest;}
};
