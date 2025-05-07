#include "rent.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>

void rent(Data& u) {

  std::ifstream amount_file(*u.choosen_library_name + ".txt" , std::ios::in);
  if (!amount_file.is_open()) {
    std::cout << "Currently Book Renting System Not Working." << '\n';
    return;
  }

  std::string line;

  while (std::getline(amount_file, line)) {
    if(line.find("Book Name : " ) != std::string::npos) {
      (*u.rent_book_amount) ++;
    }
  }



  std::cout << "Currently Avaliable Books. " << '\n';

  std::ifstream show_file(*u.choosen_library_name + ".txt" , std::ios::in);
  if (!show_file.is_open()) {
    std::cout << "Currently Book Renting System Not Working." << '\n';
    return;
  }

  std::string show_line;

  while (std::getline(show_file, show_line)) {
    if(show_line.find("Book Name : " ) != std::string::npos) {
      std::cout << show_line << '\n';
    }
  }
  std::cout << "Your Choice: " << '\n';
  std::cin >> *u.rent_book_choice;

  if(std::cin.fail()){
    std::cout << "Please enter a valid choice." << '\n';
    return;
  }

  if(*u.rent_book_choice > *u.rent_book_amount){
    std::cout << "Opps! We dont have that." << '\n';
    return;
  }

  std::ifstream rent_file(*u.choosen_library_name + ".txt" , std::ios::in);
  if (!rent_file.is_open()) {
    std::cout << "Currently Book Renting System Not Working." << '\n';
    return;
  }

  std::ofstream user_rent_file(*u.username + "_rent.txt" , std::ios::app);
  if (!user_rent_file.is_open()) {
    std::cout << "Currently Book Renting System Not Working." << '\n';
    return;
  }

  std::string rent_line;
  std::string string_id;
  bool same_book_data = false;

  while (std::getline(rent_file, rent_line)) {

    if (same_book_data) {
      user_rent_file << rent_line << '\n';

      if (rent_line == "/-/") {
        same_book_data = false;
      }

      continue;
    }

    string_id = rent_line.substr(0, rent_line.find('.'));

    if (string_id.empty() || !std::all_of(string_id.begin(), string_id.end(), ::isdigit)) {
      continue;
    }

    int current_id = std::stoi(string_id);

    if (current_id == *u.rent_book_choice) {
      user_rent_file << rent_line << '\n';
      same_book_data = true;
      continue;
    }
  }

  std::cout << "Successfully Rented." << '\n';
  std::cout << "You can see book details in your rent history." << '\n';

}

