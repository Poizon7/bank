#pragma once

#include <string>

class Stock {
private:
  std::string name; // The stocks name
  float numberOfStocks; // The number of available stocks
  float price; // The price of the stock

public:
  // Constructor
  Stock(std::string name, float numberOfStocks, float price);

  float TradeStock(float amount); // Function for buying and selling stock

  // Getters and setters
  std::string GetName(){return name;}
  float GetNumberOfStocks(){return numberOfStocks;}
  float GetPrice(){return price;}
};
