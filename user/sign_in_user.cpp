#include "sign_in_user.hpp"
#include <iostream>
#include <fstream>
#include "user_menu.hpp"
#include "open_library.hpp"

void sign_in_user(Data& u){

  std::cout << "Username :: " << '\n';
  std::cin >> *u.username;
  std::cout << "Password :: " << '\n';
  std::cin >> *u.password;


  std::ifstream check_file ("user.txt" , std::ios::in);
  if (!check_file.is_open()){
    std::cout << "Error opening file" << std::endl;
    return;
  }

  std::string line;
  std::string found_username;
  std::string found_password;



  while(std::getline(check_file, line)){
    if(line.find("Username : ") != std::string::npos){
      found_username = line.substr(line.find(": ") + 2);
    }else if (line.find("Password : ") != std::string::npos){
      found_password = line.substr(line.find(": ") + 2);
      if(found_username == *u.username && found_password == *u.password){
        *u.can_enter = true;
        break;
      }
    }
  }

  if(!*u.can_enter){
    std::cout << "username or password is wrong" << std::endl;
    return;
  }

  std::cout << "Welcome Back: " << *u.username << '\n';

  open_libraries(u);





}
