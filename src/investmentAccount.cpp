#include "investmentAccount.h"
#include "stock.h"
#include <iostream>
#include <string>
#include <vector>

InvestmentAccount::InvestmentAccount(std::string accountNumber, std::string cleringNumber, float tax):Account(accountNumber, cleringNumber){
  this->tax = tax;
}

void InvestmentAccount::ModifyBalance(float change){
  balance += change;
}

void InvestmentAccount::ModifyStocks(Bank* bank){
  std::vector<Stock*> stocks = bank->GetStocks();
  for (int i = 0; i < stocks.size(); i++) {
    std::cout << stocks[i]->GetName() << std::endl;
  }

  Stock* stock;

  std::string stockName;
  std::cout << "Which stock do you wish to trade: " << std::endl;
  std::cin >> stockName;

  for (int i = 0; i < stocks.size(); i++) {
    stock = stocks[i];
  }

  std::cout << stock->GetName() << std::endl;
  std::cout << "Number of stocks: " << stock->GetNumberOfStocks() << std::endl;
  std::cout << "Price: " << stock->GetPrice() << std::endl;

  std::string amount;
  std::cout << "How many do you want to buy: " << std::endl;
  std::cin >> amount;

  ModifyBalance(stock->TradeStock(std::stof(amount)));

  auto it = this->stocks.find(stockName);
  if (it != this->stocks.end()) {
    it->second += stof(amount);
  }
  else {
    this->stocks.insert(std::make_pair(stockName, stof(amount)));
  }
}

