#include "taxableBrokageAccount.h"
#include "investmentAccount.h"
#include <string>

TaxableBrokageAccount::TaxableBrokageAccount(std::string accountNumber, std::string cleringNumber, float tax):InvenstmentAccount(accountNumber, cleringNumber, tax){}

void TaxableBrokageAccount::ModifyBalance(float change){
  balance += change;
}

void TaxableBrokageAccount::ModifyStocks(){
  // Add when adding file management
}
