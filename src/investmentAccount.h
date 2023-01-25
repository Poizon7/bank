#pragma once

#include "account.h"
#include "bank.h"
#include <unordered_map>
#include <string>

class InvestmentAccount : public Account {
private:
  std::unordered_map<std::string, float> stocks;
  float tax;

public:
  // Constructor
  InvestmentAccount(std::string accountNumber, std::string cleringNumber, float tax);

  // Deconstructor
  ~InvestmentAccount();

  // Setters and getters
  void ModifyBalance(float change);
  void ModifyStocks(Bank* bank);
};
