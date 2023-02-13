#include "stock.h"
#include <stdexcept>
#include <string>

// Constructor
Stock::Stock(std::string name, float numberOfStocks, float price) {
  this->name = name;
  this->numberOfStocks = numberOfStocks;
  this->price = price;
}

// Function for buying and selling stock
float Stock::TradeStock(float amount) {
  if (amount > numberOfStocks) {
    throw std::invalid_argument("Cannot buy more stocks than available");
  }

  numberOfStocks -= amount;
  return amount * price;
}
