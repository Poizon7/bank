#include <string>

#include "account.h"

// Basic constructor setting the neccesary information
Account::Account(std::string accountNumber, std::string clearingNumber){
  this->balance = 0;
  this->accountNumber = accountNumber;
  this->clearingNumber = clearingNumber;
}
