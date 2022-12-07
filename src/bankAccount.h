#pragma once

#include "account.h"
#include <string>

class BankAccount : public Account {
protected:
  float intrest;

public:
  BankAccount(std::string accountNumber, std::string clearingNumber, float intrest);
  virtual void ModifyBalance(float change) = 0;
  float GetIntrest(){return intrest;}
};
