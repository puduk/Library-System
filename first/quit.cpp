#include <iostream>
#include "quit.hpp"
#include <fstream>
#include <cctype>


void quit(FirstData& f ) {

  std::cout << "-----------------------------------" << std::endl;
  std::cout << "Thank you for using this program!" << std::endl;
  std::cout << "Dont forget to rate us. ( 0 - 10 )" << std::endl;

  std::ofstream rate_file ("rate.txt" , std::ios::app);
  if(!rate_file.is_open()){
    std::cout << "Could not rate please try again later." << std::endl;
    return;
  }


  std::cout << "User or Library Owner ( U = User , L = Library Owner)" << '\n';
  std::cin >> *f.who;

  *f.who = std::tolower(*f.who);

  if (*f.who == 'u') {
    std::cout << "Enter your Username : " << '\n';
    std::cin >> *f.role;
    std::cout << "Enter your Rate " << '\n';
    std::cin >> *f.rate;
    while(*f.rate > 10 || *f.rate < 0){
      std::cin >> *f.rate ;
      std::cout << "Please enter between 0 and 10" << std::endl;

    }

    rate_file << "Username : " <<*f.role << " =  Rate : " << *f.rate << "\n";
  }else if(*f.who == 'l') {
    std::cout << "Enter your Library Name : " << '\n';
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::getline(std::cin,*f.role);
    std::cout << "Enter your Rate " << '\n';
    std::cin >> *f.rate;
    while(*f.rate > 10 || *f.rate < 0){
      std::cin >> *f.rate ;
      std::cout << "Please enter between 0 and 10" << std::endl;

    }

    rate_file << "Library Name : " <<*f.role << " =  Rate : " << *f.rate << "\n";
  }
}


