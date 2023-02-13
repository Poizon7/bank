#pragma once

#include <string>
#include <vector>

#include "investmentAccount.h"
#include "stock.h"
#include "user.h"
#include "privateUser.h"
#include "account.h"

class Bank {
private:
  std::string name; // The banks name
  std::vector<User*> users; // All users in the bank
  std::vector<PrivateUser*> customers; // Only private users (PrivateUsers)
  std::vector<Account*> accounts; // All accounts
  std::vector<InvestmentAccount*> investmentAccounts; // Only investment accounts
  std::vector<Stock*> stocks; // All the stocks

public:
  // Constructors
  Bank(std::string);

  // Deconstructor
  void Close();

  // Function run from main to interact with the bank
  void Login();
  void SendMoney(std::string accountNumber, float amount);

  // Seters and geters
  void AddUser(User* user, PrivateUser* customer); 
  std::vector<User*> GetUsers(){return users;};
  std::vector<PrivateUser*> GetCustomer(){return customers;}

  void AddAccount(Account* account) {accounts.push_back(account);}
  void AddInvestmentAccount(InvestmentAccount* investmentAccount){investmentAccounts.push_back(investmentAccount);}
  std::vector<Account*> GetAccounts(){return accounts;}
  std::vector<InvestmentAccount*> GetInvestmentAccounts(){return investmentAccounts;}

  std::vector<Stock*> GetStocks() {return stocks;}
  void AddStock(Stock* stock) {stocks.push_back(stock);}
};
