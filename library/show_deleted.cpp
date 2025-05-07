#include "show_deleted.hpp"
#include <iostream>
#include <fstream>

void show_deleted(LibraryData& l){

  std::cout << "Deleted Books : " << '\n';

  std::ifstream show_file(*l.library_name + "_removed.txt" , std::ios::in);
  if(!show_file.is_open()){
    std::cout << "Unable to open file." << '\n';
    return;
  }

  show_file.seekg(0, std::ios::end);
  if(show_file.tellg() == 0){
    std::cout << "There is no deleted book." << '\n';
    return;
  }

  show_file.seekg(0);

  std::string line;
  while(std::getline(show_file, line)){
    std::cout << line << '\n';
  }
}

