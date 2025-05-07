#include "create_account.hpp"
#include <iostream>
#include <fstream>
#include "library_menu.hpp"
#include "first_add.hpp"

void create_account(LibraryData& l){


  std::cin.clear();
  std::cin.ignore(1000 , '\n');
  std::cout << "Library Name : " << '\n';
  std::getline(std::cin, *l.library_name);

  std::ifstream library_file("library.txt" , std::ios::in);
  if(!library_file.is_open()){
    std::cout << "Can not create library account currently" << '\n';
    return;
  }

  std::string amount_line;
  while(std::getline(library_file, amount_line)){
    if(amount_line.find("Library Name : ") != std::string::npos){
      (*l.library_amount) ++;
    }
  }

  //
  std::ifstream name_file("library.txt" , std::ios::in);
  if (!name_file.is_open()){
    std::cout << "Currently can not create library account " << '\n';
    return;
  }

  std::string check_line;
  std::string found_name;
  bool can_create = true;

  while (std::getline(name_file, check_line)){
    if(check_line.find("Library Name : ") != std::string::npos){
      found_name = check_line.substr(check_line.find(":") + 2);
      if(found_name == *l.library_name){
        std::cout << "This library name already exists" << '\n';
        can_create = false;
      }
    }
  }

  if(!can_create){
    std::cout << "This library already exists" << '\n';
    return;
  }


  std::cout << "Library Password : " << '\n';
  std::cin >> *l.library_password;
  std::cout << "Library Owner : " << '\n';
  std::cin.clear();
  std::cin.ignore(1000 , '\n');
  std::getline(std::cin , *l.library_owner);
  std::cout << "Library Address : " << '\n';
  std::getline(std::cin , *l.library_address);

  //

  std::ifstream address_file("library.txt" , std::ios::in);
  if (!address_file.is_open()){
    std::cout << "Currently can not create library account " << '\n';
    return;
  }

  std::string address_line;
  std::string found_address;

  while (std::getline(address_file, address_line)){
    if(address_line.find("Library Address : ") != std::string::npos){
      found_address = address_line.substr(address_line.find(":") + 2);
      if(found_address == *l.library_address){
        std::cout << "This library address already exists" << '\n';
        return;
      }
    }
  }

  //
  std::cout << "Library Email : " << '\n';
  std::cin >> *l.library_email;
  std::ifstream email_file("library.txt" , std::ios::in);
  if (!email_file.is_open()){
    std::cout << "Currently can not create library account " << '\n';
    return;
  }

  std::string email_line;
  std::string found_email;

  while (std::getline(email_file, email_line)){
    if(email_line.find("Library Email : ") != std::string::npos){
      found_email = email_line.substr(email_line.find(":") + 2);
      if(found_email == *l.library_email){
        std::cout << "This library email already exists" << '\n';
        return;
      }
    }
  }
  //
  std::cout << "Library Phone : " << '\n';
  std::cin >> *l.library_phone;
  std::ifstream phone_file("library.txt" , std::ios::in);
  if (!phone_file.is_open()){
    std::cout << "Currently can not create library account " << '\n';
    return;
  }

  std::string phone_line;
  std::string found_phone;

  while (std::getline(phone_file, phone_line)){
    if(phone_line.find("Library Phone : ") != std::string::npos){
      found_phone = phone_line.substr(phone_line.find(":") + 2);
      if(found_phone == *l.library_phone){
        std::cout << "This library phone number already exists" << '\n';
        return;
      }
    }
  }

  (*l.library_amount)++;

  std::ofstream create_file("library.txt" , std::ios::app);
  if(!create_file.is_open()){
    std::cout << "Currently can not create library account " << '\n';
    return;
  }

  create_file << *l.library_amount << ". " << "Library Name : " << *l.library_name << '\n';
  create_file << *l.library_amount << ". " << "Library Password : " << *l.library_password << '\n';
  create_file << *l.library_amount << ". " << "Library Address : " << *l.library_address << '\n';
  create_file << *l.library_amount << ". " << "Library Owner : " << *l.library_owner << '\n';
  create_file << *l.library_amount << ". " << "Library Email : " << *l.library_email << '\n';
  create_file << *l.library_amount << ". " << "Library Phone : " << *l.library_phone << '\n';
  create_file << "/-/" << '\n';


  first_add(l);



}




























