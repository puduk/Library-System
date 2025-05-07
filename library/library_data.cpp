#include "library_data.hpp"
#include <iostream>

LibraryData::LibraryData(){

  library_name = new std::string;
  library_password = new std::string;
  library_email = new std::string;
  library_phone = new std::string;
  library_owner = new std::string;
  library_address = new std::string;

  can_sign_in = new bool(false);

  book_name = new std::string;
  book_author = new std::string;
  book_page = new int;
  book_category = new std::string;
  book_date = new std::string;
  book_price = new double;

  book_amount = new int(0);
  book_deleter_amount = new int(0);
  book_updater_amount = new int(0);
  library_amount = new int(0);

  menu_choice = new int;
  deleter_choice = new int;
  book_updater_choice = new int;
  updated_price = new double;

}

LibraryData::~LibraryData(){
  delete library_name;
  delete library_password;
  delete library_email;
  delete library_phone;
  delete library_owner;
  delete library_address;


  delete book_name;
  delete book_author;
  delete book_page;
  delete book_category;
  delete book_date;
  delete book_price;

  delete book_amount;
  delete book_deleter_amount;
  delete book_updater_amount;
  delete library_amount;

  delete menu_choice;
  delete deleter_choice;
  delete book_updater_choice;
  delete updated_price;

  delete can_sign_in;

}

