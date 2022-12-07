#pragma once

#include <string>

class User {
private:
  std::string name;
  std::string socialSecurityNumber;
  std::string password;

public:
  User(std::string name, std::string socialSecurityNumber, std::string password);
  virtual bool Menu() = 0;
  bool CheckPassword(std::string password);
  std::string GetName(){ return name; }
  std::string GetSocialSecurityNumber(){return socialSecurityNumber;}
};
