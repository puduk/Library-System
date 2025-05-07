#include "update.hpp"
#include <iostream>
#include <fstream>
void update(LibraryData& l){

  std::ifstream amount_file(*l.library_name + ".txt" , std::ios::in);
  if(!amount_file.is_open()){
    std::cout << "Can not update any book data." << '\n';
    return;
  }

  std::string amount_line;
  while(std::getline(amount_file, amount_line)){
    if(amount_line.find("Book Name : ") != std::string::npos){
      (*l.book_updater_amount) ++;
    }
  }

  std::ifstream show_file (*l.library_name + ".txt" , std::ios::in);
  if (!show_file.is_open()){
    std::cout << "Can not update any book data." << '\n';
    return;
  }

  std::string line;


  std::cout << "Current books and prices. " << '\n';

  std::cout << "--------------------------" << '\n';
  while(std::getline(show_file, line)){
    if(line.find("Book Name : " ) != std::string::npos || line.find("Book Price : ") != std::string::npos){
      std::cout << line << '\n';
    }
  }
  std::cout << "--------------------------" << '\n';
  std::cout << "Your choice." << '\n';
  std::cin >> *l.book_updater_choice;

  if(std::cin.fail()){
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Please enter a number. " << '\n';
    return;

  }

  if(*l.book_updater_choice > *l.book_updater_amount){
    std::cout << "Opps! We dont have that." << '\n';
    return;
  }

  std::cout << "Enter new book price." << '\n';
  std::cin >> *l.updated_price;

  std::ifstream update_file(*l.library_name + ".txt" , std::ios::in);
  if(!update_file.is_open()){
    std::cout << "Can not update any book data." << '\n';
    return;
  }
  std::ofstream temp_file("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Can not open temp file." << '\n';
    return;
  }

  std::string update_line;
  std::string string_id;

  while(std::getline(update_file, update_line)){

    string_id = update_line.substr(0, update_line.find("."));
    int current_id = -1;
    try{
      current_id = std::stoi(string_id);
    }catch(std::exception& e){
      temp_file << update_line << '\n';
      continue;
    }


    if(current_id == *l.book_updater_choice){


      if(update_line.find("Book Price : ") != std::string::npos){
        temp_file << current_id << ". " << "Book Price : " << *l.updated_price << '\n';
      }else{
        temp_file << update_line << '\n';
      }

    }else{

      temp_file << update_line << '\n';

    }

  }

  temp_file.close();
  update_file.close();

  std::string filename = *l.library_name + ".txt";
  std::remove(filename.c_str());
  std::rename("temp.txt", filename.c_str());

  std::cout << "Book Price Updated to: " << *l.updated_price << '\n';
}
