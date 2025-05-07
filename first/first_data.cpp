#include "first_data.hpp"


FirstData::FirstData(){

  first_page_choice = new int;
  rate = new int(-1);
  who  = new char;

  role = new std::string;


}

FirstData::~FirstData(){
  delete first_page_choice;
  delete rate;
  delete who;
  delete role;
}


