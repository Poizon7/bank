#pragma once

#include "account.h"
#include <unordered_map>
#include <string>

class InvestmentAccount : public Account {
private:
  std::unordered_map<std::string, float> stocks;
  float tax;

public:
  InvestmentAccount(std::string accountNumber, std::string cleringNumber, float tax);
  void ModifyBalance(float change);
  void ModifyStocks();
};
