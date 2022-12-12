#include "investmentSavingsAccount.h"
#include "investmentAccount.h"
#include <string>

InvestmentSavingsAccount::InvestmentSavingsAccount(std::string accountNumber, std::string clearingNumber, float tax):InvenstmentAccount(accountNumber, clearingNumber, tax){}

void InvestmentSavingsAccount::ModifyBalance(float change){
  balance += change;
}

void InvestmentSavingsAccount::ModifyStocks(){
  // Add when doing file managment
}
