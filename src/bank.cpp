#include <string>
#include <iostream>
#include <vector>

#include "administrator.h"
#include "bank.h"
#include "privateUser.h"

// Basic constructor that sets the banks name
Bank::Bank(std::string name){
  this->name = name;
  users.push_back(new Administrator("root", "root", "root", this)); // Add an admin to the bank
}

void Bank::Login() {
  bool run = true;

  std::string name;
  std::string password;

  // Loop that runs while the program is active
  while (run) {
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;

    std::cout << "Enter password: " << std::endl;
    std::cin >> password;

    // Loops through all users and checks if the supplied name and password match a user
    for (long unsigned int i = 0; i < users.size(); i++) {
      // If name and password match then give the user access to their account
      if (users[i]->GetName() == name && users[i]->CheckPassword(password)){
        run = users[i]->Menu();
        break;
      }
    }
    std::cout << "Incorrect username or password" << std::endl;
  }
}

// Adds a user to the bank
void Bank::AddUser(User *user, PrivateUser* customer){
  users.push_back(user);

  // If the user is a customer add it to that list as well
  if (customer != nullptr){
    customers.push_back(customer);
  }
}
