#pragma once

#include "bankAccount.h"
#include <string>

class TransactionAccount : public BankAccount {
public:
  TransactionAccount(std::string accountNumber, std::string clearingNumber, float intrest);
  void ModifyBalance(float change);
};
