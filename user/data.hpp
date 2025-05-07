#ifndef DATA_H
#define DATA_H
#include <iostream>

class Data {
  public:

    std::string* username;
    std::string* password;

    std::string* choosen_library_name;

    bool* can_enter;

    int* user_amount;
    int* user_menu_choice;
    int* book_amount;

    int* buy_book_choice;
    int* library_choice;
    int* library_amount;
    int* rent_book_amount;
    int* rent_book_choice;


    Data();
    ~Data();
};

#endif
