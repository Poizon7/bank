#include "bankAccount.h"
#include <string>

BankAccount::BankAccount(std::string accountNumber, std::string clearingNumber, float intrest):Account(accountNumber, clearingNumber){
  this->intrest = intrest;
}
