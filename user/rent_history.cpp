#include "rent_history.hpp"
#include <iostream>
#include <fstream>


void rent_history(Data& u) {

  std::cout << "------------------" << '\n';
  std::cout << "Rent history" << '\n';

  std::ifstream rent_file (*u.username + "_rent.txt", std::ios::in);
  if (!rent_file.is_open()) {
    std::cout << "Currently Book Renting System Not Working." << '\n';
    return;
  }

  rent_file.seekg(0, std::ios::end);
  if (rent_file.tellg() == 0) {
    std::cout << "There is no rented book." << '\n';
    return;
  }

  rent_file.seekg(0, std::ios::beg);

  std::string rent_line;

  while(std::getline(rent_file, rent_line)) {
    std::cout << rent_line << '\n';

  }


}

