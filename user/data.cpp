#include "data.hpp"
#include <iostream>


Data::Data(){

  username = new std::string;
  password = new std::string;

  choosen_library_name = new std::string;

  user_amount = new int(0);
  book_amount = new int(0);
  library_amount = new int(0);
  rent_book_amount = new int(0);

  can_enter = new bool(false);

  buy_book_choice = new int;
  library_choice = new int;
  rent_book_choice = new int;
  user_menu_choice = new int;

}

Data::~Data(){
  delete username;
  delete password;
  delete user_amount;
  delete library_amount;
  delete book_amount;
  delete library_choice;
  delete rent_book_choice;
  delete buy_book_choice;
  delete library_choice;
  delete rent_book_choice;
  delete user_menu_choice;
  delete can_enter;

}
