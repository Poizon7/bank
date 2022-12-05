#pragma once

#include <string>

class User {
private:
  std::string name;
  std::string password;

public:
  User(std::string name, std::string password);
  virtual void Menu() = 0;
  bool CheckPassword(std::string password);
  std::string GetName(){ return name; }
};
