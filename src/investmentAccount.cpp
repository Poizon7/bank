#include "investmentAccount.h"
#include <string>

InvestmentAccount::InvestmentAccount(std::string accountNumber, std::string cleringNumber, float tax):Account(accountNumber, cleringNumber){
  this->tax = tax;
}

void InvestmentAccount::ModifyBalance(float change){
  balance += change;
}

void InvestmentAccount::ModifyStocks(){
  // Add when doing file managment
}
