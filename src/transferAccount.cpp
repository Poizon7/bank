#include "transferAccount.h"
#include "bankAccount.h"
#include <string>

TransactionAccount::TransactionAccount(std::string accountNumber, std::string clearingNumber, float intrest):BankAccount(accountNumber, clearingNumber, intrest){}

void TransactionAccount::ModifyBalance(float change) {
  balance += change;
}
