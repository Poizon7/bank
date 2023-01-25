#pragma once

#include <string>

class Stock {
private:
  std::string name;
  float numberOfStocks;
  float price;

public:
  Stock(std::string name, float numberOfStocks, float price);

  float TradeStock(float amount);

  std::string GetName(){return name;}
  float GetNumberOfStocks(){return numberOfStocks;}
  float GetPrice(){return price;}
};
