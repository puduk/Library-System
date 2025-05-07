#include "library_menu.hpp"
#include <iostream>
#include "add.hpp"
#include "delete.hpp"
#include "show_deleted.hpp"
#include "update.hpp"




void library_menu(LibraryData& l  ){


  while(true) {

    std::cout << "1 :: for add book " << '\n';
    std::cout << "2 :: for delete book " << '\n';
    std::cout << "3 :: for update book price " << '\n';
    std::cout << "4 :: for showing deleted books" << '\n';
    std::cout << "5 :: Quit" << '\n';
    std::cout << "---------------------------" << '\n';
    std::cin >> *l.menu_choice;

    if(std::cin.fail()){
      std::cout << "Please enter a number" << '\n';
      return;
    }

    switch(*l.menu_choice){
      case 1:
        add(l);
      break;
      case 2:
        deleter(l);
      break;
      case 3:
        update(l);
      break;
      case 4:
        show_deleted(l);
      break;
      case 5:
        std::cout << "Goodbye! " << *l.library_name << '\n';
      exit(0);
      default:
        std::cout << "Invalid choice." << '\n';
    }


  }

}