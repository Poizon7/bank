#include "bankAccount.h"
#include <string>

// Constructor setting intrest of the account
BankAccount::BankAccount(std::string accountNumber, std::string clearingNumber, float intrest):Account(accountNumber, clearingNumber){
  this->intrest = intrest;
}
