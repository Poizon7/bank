#pragma once

#include "investmentAccount.h"

class InvestmentSavingsAccount : public InvenstmentAccount {
public:
  InvestmentSavingsAccount(std::string accountNumber, std::string clearingNumber, float tax);
  void ModifyBalance(float change) override;
  void ModifyStocks() override;
};
