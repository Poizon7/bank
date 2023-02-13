#pragma once

class PrivateUser;

#include "account.h"
#include "bank.h"
#include "privateUser.h"
#include <unordered_map>
#include <string>


class InvestmentAccount : public Account {
private:
  std::unordered_map<std::string, float> stocks; // List of all the stocks owned by the account
  float tax; // The tax paid when selling stocks

public:
  // Constructor
  InvestmentAccount(std::string accountNumber, std::string cleringNumber, float tax);

  // Deconstructor
  ~InvestmentAccount();

  // Setters and getters
  void ModifyBalance(float change);
  void ModifyStocks(Bank* bank);
  std::unordered_map<std::string, float> GetStocks(){return stocks;}
};
