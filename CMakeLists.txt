cmake_minimum_required(VERSION 4.0)
project(Library)

set(CMAKE_CXX_STANDARD 20)

add_executable(Library main.cpp


        first/first_data.cpp
        first/first_page.cpp
        first/quit.cpp

        user/data.cpp
        user/sign_in_user.cpp
        user/create_account_user.cpp
        user/buy.cpp
        user/buy_history.cpp
        user/rent.cpp
        user/rent_history.cpp
        user/open_library.cpp
        user/user_menu.cpp

        library/library_data.cpp
        library/sign_in.cpp
        library/create_account.cpp
        library/add.cpp
        library/delete.cpp
        library/show_deleted.cpp
        library/update.cpp
        library/library_menu.cpp
        library/first_add.cpp



)
