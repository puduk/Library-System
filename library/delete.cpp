#include "delete.hpp"
#include <iostream>
#include <fstream>


void deleter(LibraryData& l){

  std::ifstream amount_file(*l.library_name + ".txt" , std::ios::in);
  if(!amount_file.is_open()){
    std::cout << "Currently we can not delete any book." << '\n';
    return;
  }

  std::string amount_line;
  while(std::getline(amount_file, amount_line)){
    if(amount_line.find("Book Name : ") != std::string::npos){
      (*l.book_deleter_amount)++ ;
    }
  }


  std::ifstream show_file(*l.library_name + ".txt", std::ios::in);
  if(!show_file.is_open()){
    std::cout << "Can not delete book data currently." << '\n';
    return;
  }
  std::cout << "Current books." << '\n';
  std::string line;
  while(std::getline(show_file, line)){
    if(line.find("Book Name : ") != std::string::npos){
      std::cout << line << '\n';
    }
  }

  std::cout << "----------------------------" << '\n';
  std::cout << "Your Choice: " << '\n';
  std::cin >> *l.deleter_choice;

  if(std::cin.fail()){
    std::cout << "Please enter a number." << '\n';
    return;
  }

  if(*l.deleter_choice > *l.book_deleter_amount){
    std::cout << "Opps! We dont have that. " << '\n';
    return;
  }


  std::ifstream delete_file(*l.library_name + ".txt", std::ios::in);
  if(!delete_file.is_open()){
    std::cout << "Can not delete book data currently." << '\n';
    return;
  }
  std::ofstream temp_file("book_temp.txt",  std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Can not open book temp file." << '\n';
    return;
  }
  std::ofstream removed_file(*l.library_name + "_removed.txt", std::ios::app);
  if(!removed_file.is_open()){
    std::cout << "Can not delete book data currently." << '\n';
    return;
  }


  std::string reader_line;
  std::string deleter_id;


  while(std::getline(delete_file, reader_line)){

    deleter_id = reader_line.substr(0, reader_line.find("."));
    int current_id = -1;

      try {
        current_id = std::stoi(deleter_id);
      } catch (std::exception& e) {
        temp_file << reader_line << '\n';
        continue;
      }
    if(current_id == *l.deleter_choice){
      removed_file << reader_line << '\n';
      continue;
    }else {
      temp_file << reader_line << '\n';
    }



  }
  removed_file << "/-/" << '\n';

  delete_file.close();
  temp_file.close();

  std::string filename = *l.library_name + ".txt";
  std::remove(filename.c_str());
  std::rename("book_temp.txt" , filename.c_str());


  std::cout << "Successfully deleted." << '\n';
}
