//
// Created by MaSit on 22/02/2021.
//

#include <iostream>
#include <ctype.h>
#include "contact.hpp"

int main(void){
    contact phone_book[8];

    int     i = 0;

    while (1){
        std::string input;
        std::cout << "Waiting for commands : ['EXIT', 'SEARCH', 'ADD']." << std::endl;
        std::cout << "input: ";

        std::cin >> input;
        if (input == "EXIT"){
            break;
        }
        else if (input == "ADD"){
            if (phone_book[7].isSet()){
                std::cout << "Your phonebook is full !" << std::endl;
                continue;
            }

            std::string first_name;
            std::string last_name;
            std::string nickname;
            std::string login;
            std::string postal_address;
            std::string email_address;
            std::string phone_number;
            std::string birthday_date;
            std::string favorite_meal;
            std::string underwear_color;
            std::string darkest_secret;

            std::cout << "first name: " << std::endl << "input: ";
            std::cin >> first_name;

            std::cout << "last name: " << std::endl << "input: ";
            std::cin >> last_name;

            std::cout << "nickname: " << std::endl << "input: ";
            std::cin >> nickname;

            std::cout << "login: " << std::endl << "input: ";
            std::cin >> login;

            std::cout << "postal_address: " << std::endl << "input: ";
            std::cin >> postal_address;

            std::cout << "email_address: " << std::endl << "input: ";
            std::cin >> email_address;

            std::cout << "phone_number: " << std::endl << "input: ";
            std::cin >> phone_number;

            std::cout << "birthday_date: " << std::endl << "input: ";
            std::cin >> birthday_date;

            std::cout << "favorite_meal: " << std::endl << "input: ";
            std::cin >> favorite_meal;

            std::cout << "underwear_color: " << std::endl << "input: ";
            std::cin >> underwear_color;

            std::cout << "darkest_secret: " << std::endl << "input: ";
            std::cin >> darkest_secret;

            phone_book[i].setContact(first_name, last_name, nickname, login, postal_address, email_address, phone_number, birthday_date, favorite_meal, underwear_color, darkest_secret);
            std::cout << "Contact " << first_name << " has been created with the following info : " << std::endl;
            phone_book[i++].display();
        }
        else if (input == "SEARCH"){
            for (int j = 0; j < 8; j++) {
                if (phone_book[j].isSet()) {

                }
                std::cout << "Witch contact you want to display ? " << std::endl;
            }
        }
//        else if (input == "FILL"){
//
//            phone_book[i++].setContact("titi", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//
//            phone_book[i++].setContact("tata", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//
//            phone_book[i++].setContact("toto", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("tutu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("flo", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("malo", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("mathieu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("jududu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//        }
        else{
            std::cout << "Command must be one of the following : 'EXIT', 'SEARCH' or 'ADD'." <<std::endl;
        }
    }

    return 0;
}