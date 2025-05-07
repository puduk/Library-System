#include "user_menu.hpp"
#include <iostream>
#include <fstream>
#include "buy.hpp"
#include "rent.hpp"
#include "buy_history.hpp"
#include "rent_history.hpp"

void user_menu(Data& u){



  while(true) {

    std::cout << "-----------------------------" << '\n';
    std::cout << "1 :: for buy book" << '\n';
    std::cout << "2 :: for rent book" << '\n';
    std::cout << "3 :: for purchased history" << '\n';
    std::cout << "4 :: for rented history" << '\n';
    std::cout << "5 :: Quit" << '\n';
    std::cout << "-----------------------------" << '\n';
    std::cin >> *u.user_menu_choice;

    if(std::cin.fail()){
      std::cout << "INVALID INPUT" << '\n';
      return user_menu(u) ;
    }

    switch(*u.user_menu_choice){
      case 1:
        buy_menu(u);
      break;
      case 2:
        rent(u);
      break;
      case 3:
        buy_history(u);
      break;
      case 4:
        rent_history(u);
      break;
      case 5:
        std::cout << "Goodbye!" << *u.username <<'\n';
      exit(0);
      default:
        std::cout << "INVALID INPUT'" << '\n';

    }


  }

}
