#include "investmentAccount.h"
#include "account.h"
#include <string>

InvenstmentAccount::InvenstmentAccount(std::string accountNumber, std::string cleringNumber, float tax):Account(accountNumber, cleringNumber){
  this->tax = tax;
}
