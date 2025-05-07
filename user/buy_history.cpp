#include "buy_history.hpp"
#include <iostream>
#include <fstream>



void buy_history(Data& u) {

  std::cout << "------------------" << '\n';
  std::cout << "Purchased history" << '\n';
  std::ifstream check_file (*u.username + "_bought.txt" , std::ios::in);
  if (!check_file.is_open()) {
    std::cout << "Currently we can not show you the history of purchase." << '\n';
    return;
  }

  check_file.seekg(0, std::ios::end);
  if (check_file.tellg() == 0) {
    std::cout << "There is no any purchased book." << '\n';
    return;
  }

  check_file.seekg(0, std::ios::beg);

  std::string check_line ;
  while (std::getline(check_file, check_line)) {
    std::cout << check_line << '\n';
  }



}

