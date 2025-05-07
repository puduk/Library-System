#include "open_library.hpp"
#include <iostream>
#include <fstream>
#include <algorithm> // for std::replace
#include "user_menu.hpp"

void open_libraries(Data& u){

  std::cout << "------------------------------" << '\n';
  std::cout << "Current avaliable libraries:" << '\n';

  std::ifstream amount_file("library.txt", std::ios::in);
  if(!amount_file.is_open()){
    std::cout << "Currently no any avaliable library." << '\n';
    return;
  }

  std::string amount_line;
  while(std::getline(amount_file, amount_line)){
    if(amount_line.find("Library Name : ") != std::string::npos){
      (*u.library_amount)++;
    }
  }
  amount_file.close();

  std::ifstream show_library("library.txt", std::ios::in);
  if(!show_library.is_open()){
    std::cout << "Currently no any avaliable library." << '\n';
    return;
  }

  std::string line;
  while (std::getline(show_library, line)){
    if(line.find("Library Name : ") != std::string::npos){
      std::cout << line << '\n';
    }
  }
  show_library.close();

  std::cout << "Which library you want to open?" << '\n';
  std::cin >> *u.library_choice;

  if(std::cin.fail()){
    std::cout << "Please enter a number." << '\n';
    return;
  }
  if(*u.library_choice > *u.library_amount ){
    std::cout << "Oops! We don't have that." << '\n';
    return;
  }

  std::ifstream choose_file("library.txt", std::ios::in);
  if(!choose_file.is_open()){
    std::cout << "Currently no any avaliable library." << '\n';
    return;
  }

  std::string choose_line;
  std::string key = std::to_string(*u.library_choice) + ". Library Name : ";

  while(std::getline(choose_file, choose_line)){
    if(choose_line.find(key) != std::string::npos){
      std::string raw_name = choose_line.substr(key.length());

      while (!raw_name.empty() && std::isspace(raw_name.front()))
        raw_name.erase(raw_name.begin());
      while (!raw_name.empty() && std::isspace(raw_name.back()))
        raw_name.pop_back();

      std::replace(raw_name.begin(), raw_name.end(), ' ', '_');

      *u.choosen_library_name = raw_name;
      break;
    }
  }
  choose_file.close();

  user_menu(u);
}
