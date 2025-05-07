#include "buy.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>


void buy_menu(Data& u ){



  std::ifstream book_amount(*u.choosen_library_name + ".txt" , std::ios::in );
  if(!book_amount.is_open()){
    std::cout << "File could not be opened " << std::endl;
    return;
  }

  std::string amount_line;
  while(std::getline(book_amount, amount_line)){
    if(amount_line.find("Book Name : ") != std::string::npos){
      (*u.book_amount)++;
    }
  }



  std::ifstream books_file(*u.choosen_library_name + ".txt" , std::ios::in);
  if(!books_file.is_open()){
    std::cout << "Error opening file" << '\n';
    return;
  }

  std::cout << "Currently Avaliable Books" << '\n';

  std::string book_name;
  std::string line;


  while(std::getline(books_file, line)){
    if(line.find("Book Name : ") != std::string::npos){
      book_name = line;
      std::cout << book_name << '\n';
    }
  }
  std::cout << "Your Choice: " << '\n';
  std::cin >> *u.buy_book_choice;




  if(std::cin.fail()){
    std::cout << "invalid input" << '\n';
    return;
  }

  if(*u.buy_book_choice > *u.book_amount ) {
    std::cout << "Opps! We dont have that : " << '\n';
    return;
  }

  std::ifstream buy_file(*u.choosen_library_name + ".txt"  , std::ios::in);
  if(!buy_file.is_open()){
    std::cout << "Error opening file" << '\n';
    return;
  }
  std::ofstream temp_file("temp.txt" , std::ios::out);
  if(!temp_file.is_open()){
    std::cout << "Error opening file" << '\n';
    return;
  }
  std::ofstream bought_file(*u.username+"_bought.txt" , std::ios::app);
  if(!bought_file.is_open()){
    std::cout << "Error opening file" << '\n';
    return;
  }


  std::string buy_line;
  std::string string_id;
  bool same_book_data = false;

  while(std::getline(buy_file, buy_line)){

    if (same_book_data) {
      bought_file << buy_line << '\n';

      if (buy_line == "/-/") {
        same_book_data = false;
      }

      continue;
    }

    string_id = buy_line.substr(0, buy_line.find("."));

    if (string_id.empty() || !std::all_of(string_id.begin(), string_id.end(), ::isdigit)) {
      temp_file << buy_line << '\n';
      continue;
    }

    int current_id = std::stoi(string_id);

    if(current_id == *u.buy_book_choice){
      bought_file << buy_line << '\n';
      same_book_data = true;
      continue;
    }

    temp_file << buy_line << '\n';
  }


  buy_file.close();
  temp_file.close();

  std::string file_name = *u.choosen_library_name + ".txt" ;
  std::remove(file_name.c_str());
  std::rename("temp.txt", file_name.c_str());



  std::cout << "Purchase Successful!" << '\n';
}

