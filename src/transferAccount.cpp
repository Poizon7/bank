#include "transferAccount.h"
#include "bankAccount.h"
#include <string>

// Constructor
TransactionAccount::TransactionAccount(std::string accountNumber, std::string clearingNumber, float intrest):BankAccount(accountNumber, clearingNumber, intrest){}

// Change the balance of the account based on the supplied amount
void TransactionAccount::ModifyBalance(float change) {
  balance += change;
}
