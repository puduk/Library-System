#include "sign_in.hpp"
#include <iostream>
#include <fstream>
#include "library_menu.hpp"

void sign_in(LibraryData& l) {

  std::cin.clear();
  std::cin.ignore(1000 , '\n');

  std::cout << "Name: " << '\n';
  std::getline(std::cin, *l.library_name);
  std::cout << "Password: " << '\n';
  std::cin >> *l.library_password;

  std::ifstream check_file("library.txt" , std::ios::in);
  if (!check_file.is_open()) {
    std::cout << "Currently can not sign in the system." << '\n';
    return;
  }

  std::string line;
  std::string found_name;
  std::string found_password;


  while (std::getline(check_file, line)) {
    if(line.find("Library Name : ") != std::string::npos) {
      found_name = line.substr(line.find(":") + 2);
    }else if(line.find("Library Password : ") != std::string::npos) {
      found_password = line.substr(line.find(":") + 2);
      if(found_name == *l.library_name && found_password == *l.library_password) {
        *l.can_sign_in = true;
      }
    }
  }

  if(!*l.can_sign_in) {
    std::cout << "Library Name or Password not found." << '\n';
    return;
  }

  std::cout << "Welcome, " << *l.library_name << "!" << '\n';


  std::ifstream show_file(*l.library_name + ".txt" , std::ios::in);
  if (!show_file.is_open()) {
    std::cout << "Can not load library data." << '\n';
    return;
  }

  std::string show_line;
  std::cout << "Library system loaded. Book list:\n";


  while(std::getline(show_file, show_line)) {
    std::cout << show_line << '\n';
  }

  library_menu(l);

}
