#include "create_account_user.hpp"
#include <iostream>
#include <fstream>
#include "user_menu.hpp"

void create_account_user(Data& u){

  std::cout << "Create Username : " << std::endl;
  std::cin >> *u.username;

  std::ifstream username_file ("user.txt" , std::ios::in);
  if (!username_file.is_open()){
    std::cout << "Error opening file" << std::endl;
    return;
  }

  std::string username_line;
  while(std::getline(username_file, username_line)){
    if(username_line.find(*u.username) != std::string::npos){
      std::cout << "This username already exists" << std::endl;
      return;
    }
  }

  std::cout << "Create Password : " << std::endl;
  std::cin >> *u.password;

  std::ifstream reader_file ("user.txt" , std::ios::in);
  if (!reader_file.is_open()){
    std::cout << "Error opening file" << std::endl;
    return;
  }


  std::string reader_line;
  while(std::getline(reader_file, reader_line)){
    if(reader_line.find("Username : ") != std::string::npos){
      (*u.user_amount)++ ;
    }
  }



  std::ofstream create_file ("user.txt" , std::ios::app);
  if (!create_file.is_open()){
    std::cout << "Error opening file" << std::endl;
    return;
  }


  (*u.user_amount)++;
  create_file << *u.user_amount << ". " << "Username : " << *u.username << '\n';
  create_file << *u.user_amount << ". " << "Password : " << *u.password << '\n';
  create_file << "/-/" << '\n';


  std::cout << *u.username << " Account Successfully Created" << '\n';

  user_menu(u);


}














