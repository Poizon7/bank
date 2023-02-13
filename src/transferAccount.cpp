#include "transferAccount.h"
#include "bankAccount.h"
#include <stdexcept>
#include <string>

// Constructor
TransactionAccount::TransactionAccount(std::string accountNumber, std::string clearingNumber, float intrest):BankAccount(accountNumber, clearingNumber, intrest){}

// Change the balance of the account based on the supplied amount
void TransactionAccount::ModifyBalance(float change) {
  if ((change < 0) && (change * -1 > balance)) {
    throw std::invalid_argument("Cannot send more money than you have");
  }
  balance += change;
}
