#pragma once

#include "investmentAccount.h"
#include <string>

class TaxableBrokageAccount : public InvenstmentAccount {
public:
  TaxableBrokageAccount(std::string accountNumber, std::string clearingNumber, float tax);
  void ModifyBalance(float change) override;
  void ModifyStocks() override;
};
