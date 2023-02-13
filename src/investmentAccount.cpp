#include "investmentAccount.h"
#include "stock.h"

#include <ios>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

// Constructor that sets the tax
InvestmentAccount::InvestmentAccount(std::string accountNumber, std::string cleringNumber, float tax):Account(accountNumber, cleringNumber){
  this->tax = tax;
}

// Change the amount of money in the account availeble for trading
void InvestmentAccount::ModifyBalance(float change){
  balance += change;
}

// Function for buying stocks
void InvestmentAccount::ModifyStocks(Bank* bank){
  std::vector<Stock*> stocks = bank->GetStocks();

  // Print the name of all the stocks
  for (int i = 0; i < stocks.size(); i++) {
    std::cout << stocks[i]->GetName() << std::endl;
  }

  Stock* stock;

  std::string stockName;
  std::cout << "Which stock do you wish to trade: " << std::endl;
  std::cin >> stockName;

  // Set the stock to the one chosen
  for (int i = 0; i < stocks.size(); i++) {
    if (stockName == stocks[i]->GetName()) {
      stock = stocks[i];
      break;
    }
  }

  std::cout << stock->GetName() << std::endl;
  std::cout << "Number of stocks: " << stock->GetNumberOfStocks() << std::endl;
  std::cout << "Price: " << stock->GetPrice() << std::endl;

  float amount;

  // Loop while the entered amount is invalid
  while (true) {
    try {
      std::cout << "How many do you want to buy: " << std::endl;
      std::cin >> amount;

      std::unordered_map<std::string, float>::iterator it = this->stocks.find(stockName);
      if (it != this->stocks.end()) {
        if ((amount < 0) && (it->second < amount * -1)) {
          throw std::invalid_argument("Cannot sell more than you own");
        }
      }
      else {
        this->stocks.insert(std::make_pair(stockName, amount));
      }

      try {
        ModifyBalance(stock->TradeStock(amount) * -1);
        break;
      }
      catch (std::invalid_argument e) {
        std::cerr << e.what() << std::endl;
      }
    }
    catch (std::invalid_argument e) {
      std::cerr << e.what() << std::endl;
    }
    catch (std::ios_base::failure) {
      std::cerr << "Input must be a number" << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  std::unordered_map<std::string, float>::iterator it = this->stocks.find(stockName);
  if (it != this->stocks.end()) {
    it->second += amount;
  }
  else {
    this->stocks.insert(std::make_pair(stockName, amount));
  }
}

