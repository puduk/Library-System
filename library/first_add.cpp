#include "first_add.hpp"
#include <iostream>
#include <fstream>

void first_add(LibraryData& l){

  std::cin.clear();
  std::cin.ignore(1000, '\n');

  std::cout << "Add your first book data." << '\n';
  std::cout << "--------------" << '\n';
  std::cout << "Book Name: " << '\n';
  std::getline(std::cin,*l.book_name);
  std::cout << "Book Date: " << '\n';
  std::cin >> *l.book_date;
  std::cout << "Book Category: " << '\n';
  std::cin >> *l.book_category;
  std::cout << "Book Price: " << '\n';
  if(std::cin.fail()){
    std::cout << "Please enter a number";
    return;
  }
  std::cin >> *l.book_price;
  std::cout << "Book Page: " << '\n';
  std::cin >> *l.book_page;
  if(std::cin.fail()){
    std::cout << "Please enter a number";
    return;
  }
  std::cin.clear();
  std::cin.ignore(1000, '\n');
  std::cout << "Book Author: " << '\n';
  std::getline(std::cin, *l.book_author);



  std::ofstream book_file (*l.library_name + ".txt", std::ios::app);
  if(!book_file.is_open()){
    std::cout << "Can not add book to store." << '\n';
    return;
  }

  (*l.book_amount) ++;

  book_file << *l.book_amount << ". " << "Book Name : " << *l.book_name << '\n';
  book_file << *l.book_amount << ". " << "Book Date : " << *l.book_date << '\n';
  book_file << *l.book_amount << ". " << "Book Category : " << *l.book_category << '\n';
  book_file << *l.book_amount << ". " << "Book Price : " << *l.book_price << '\n';
  book_file << *l.book_amount << ". " << "Book Page : " << *l.book_page << '\n';
  book_file << *l.book_amount << ". " << "Book Author : " << *l.book_author << '\n';
  book_file << "/-/" << '\n';

  std::cout << "Book: " << *l.book_name << " Data Succesfully added." << '\n';





}

