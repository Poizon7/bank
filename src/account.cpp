#include <string>

#include "account.h"

Account::Account(std::string accountNumber, std::string clearingNumber){
  this->balance = 0;
  this->accountNumber = accountNumber;
  this->clearingNumber = clearingNumber;
}
