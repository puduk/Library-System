#include "first_page.hpp"
#include <iostream>
#include "../library/library_data.hpp"
#include "../library/sign_in.hpp"
#include "../library/create_account.hpp"
#include "quit.hpp"
#include "../user/data.hpp"
#include "../user/create_account_user.hpp"
#include "../user/sign_in_user.hpp"


void sign_in_user(Data& u);
void create_account_user(Data& u);



void first_page(FirstData& f , Data& u , LibraryData& l ) {




    while (true) {

        std::cout << "--------------------------------" << std::endl;
        std::cout << "1 :: for Sign in User Account" << std::endl;
        std::cout << "2 :: for Sign in Library Account" << std::endl;
        std::cout << "3 :: for Create User Account" << std::endl;
        std::cout << "4 :: for Create Library Account" << std::endl;
        std::cout << "5 :: for Exit" << std::endl;
        std::cout << "--------------------------------" << std::endl;
        std::cin >> *f.first_page_choice;

        if(std::cin.fail()) {
            std::cout << "Please enter a valid choice" << std::endl;
            return first_page(f , u ,l);
        }


        switch(*f.first_page_choice) {
            case 1:
                sign_in_user(u);
            break;
            case 2:
                sign_in(l);
            break;
            case 3:
                create_account_user(u);
            break;
            case 4:
                create_account(l);
            break;
            case 5:
                quit(f);
            exit(0);
            default:
                std::cout << "Invalid choice" << std::endl;

        }



    }

}
