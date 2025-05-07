#ifndef LIBRARY_DATA_H
#define LIBRARY_DATA_H
#include <iostream>

class LibraryData{
  public:

    std::string* library_name;
    std::string* library_password;
    std::string* library_address;
    std::string* library_owner;
    std::string* library_email;
    std::string* library_phone;

    int* library_amount;


    bool* can_sign_in ;

    int* menu_choice;
    int* book_amount;
    int* deleter_choice;
    int* book_deleter_amount;
    int* book_updater_amount;
    int* book_updater_choice;
    double* updated_price;


    std::string* book_name;
    std::string* book_date;
    std::string* book_category;
    std::string* book_author;
    int* book_page ;
    double* book_price ;


    LibraryData();


    ~LibraryData();

};


#endif