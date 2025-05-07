#include "open_library.hpp"
#include <iostream>
#include <fstream>
#include "user_menu.hpp"

void open_libraries(Data& u){

  std::cout << "------------------------------" << '\n';
  std::cout << "Current avaliable libraries:" << '\n';

  std::ifstream amount_file ("library.txt" , std::ios::in);
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

  std::ifstream show_library("library.txt" , std::ios::in);
  if (!show_library.is_open()){
    std::cout << "Current no any avaliable library." << '\n';
    return;
  }

  std::string line;
  while (std::getline(show_library, line)){
    if(line.find("Library Name : ") != std::string::npos){
      std::cout << line << '\n';
    }
  }
  std::cout << "Which library you want to open?" << '\n';
  std::cin >> *u.library_choice;

  if(std::cin.fail()){
    std::cout << "Please enter a number." << '\n';
    return;
  }
  if(*u.library_choice > *u.library_amount ){
    std::cout << "Opps! We dont have that." << '\n';
    return;
  }


  std::ifstream choose_file ("library.txt" , std::ios::in);
  if(!choose_file.is_open()){
    std::cout << "Current no any avaliable library." << '\n';
    return;
  }


  std::string choose_line;



  while(std::getline(choose_file, choose_line)){
    if(choose_line.find(std::to_string(*u.library_choice) + ". ") != std::string::npos){
      *u.choosen_library_name = choose_line.substr(choose_line.find(":")+2);
    }
  }



  user_menu(u );

}

