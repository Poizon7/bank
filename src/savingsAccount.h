#pragma once

#include "bankAccount.h"

class SavingsAccount : public BankAccount {
private:
  float maxWithdrawl;
  float currentWithdrawl;

public:
  SavingsAccount(std::string accountNumber, std::string clearingNumber, float intrest, float maxWithdrawl);
  void ModifyBalance(float change) override;
};
