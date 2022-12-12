#pragma once

#include "account.h"
#include <unordered_map>
#include <string>

class InvenstmentAccount : public Account {
private:
  std::unordered_map<std::string, float> stocks;
  float tax;

public:
  InvenstmentAccount(std::string accountNumber, std::string cleringNumber, float tax);
  virtual void ModifyBalance(float change);
  virtual void ModifyStocks();
};
