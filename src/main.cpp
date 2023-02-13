#include "bank.h"

#include <iostream>

int main(){
  std::cin.exceptions(std::ios_base::failbit);
  Bank bank = Bank("Swedbank");
  bank.Login();
  bank.Close();
}
