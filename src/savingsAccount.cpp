#include <iostream>
#include <stdexcept>

#include "savingsAccount.h"
#include "bankAccount.h"

SavingsAccount::SavingsAccount(std::string accountNumber, std::string clearingNumber, float intrest, float maxWithdrawl):BankAccount(accountNumber, clearingNumber, intrest){
  this->maxWithdrawl = maxWithdrawl;
}

void SavingsAccount::ModifyBalance(float change){
  if (change < 0){
    if (change * -1 + currentWithdrawl > maxWithdrawl){
      balance += change;
      currentWithdrawl += change * -1;
    }
    else {
      throw std::invalid_argument("You have exeded your monthly withdrawl limit");
    }
  }
  else {
    balance += change;
  }
}
