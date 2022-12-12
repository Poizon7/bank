#pragma once

#include "bankAccount.h"
#include <string>

class TransactionAccount : public BankAccount {
public:
  // Constructor
  TransactionAccount(std::string accountNumber, std::string clearingNumber, float intrest);

  // Setters and getters
  void ModifyBalance(float change) override;
};
