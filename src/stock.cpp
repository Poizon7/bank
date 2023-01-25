#include "stock.h"
#include <string>

Stock::Stock(std::string name, float numberOfStocks, float price) {
  this->name = name;
  this->numberOfStocks = numberOfStocks;
  this->price = price;
}

float Stock::TradeStock(float amount) {
  numberOfStocks -= amount;
  return amount * price;
}
