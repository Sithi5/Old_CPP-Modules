//
// Created by MaSit on 22/02/2021.
//

#include <iostream>
#include <ctype.h>
#include <string>
#include "contact.hpp"
#include <stdio.h>
#include <stdlib.h>

void print_with_width(std::string str, int width){
    std::cout.width(width);
    std::cout << str;
    return ;
}

void print_formated_contact_info(std::string str){
    if (str.size() >= 10){
        str.resize(9);
    }
    str.append("|");
    print_with_width(str, 11);
}

int main(void){
    contact phone_book[8];
    std::string input;

    int     i = 0;

    while (1){
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
            int research_id;
            std::string display_first_name;
            std::string display_last_name;
            std::string display_nickname;
            std::string display_index;
            print_with_width("id|", 11);
            print_with_width("firstname|", 11);
            print_with_width("lastname|", 11);
            print_with_width("nickname|", 11);
            std::cout << std::endl;

            for (int j = 0; j < 8; j++) {
                if (phone_book[j].isSet()) {
                    display_first_name = phone_book[j].getFirstName();
                    display_last_name = phone_book[j].getLastName();
                    display_nickname = phone_book[j].getNickname();
                    std::cout.width(10);
                    std::cout << j << "|";
                    print_formated_contact_info(display_first_name);
                    print_formated_contact_info(display_last_name);
                    print_formated_contact_info(display_nickname);
                    std::cout << std::endl;



//                    std::cout << display_first_name << display_last_name << display_nickname;


                }
            }

            std::cout << "Which contact do you want to display ? " << std::endl;
            std::cin >> research_id;
            if (std::cin.fail() || research_id > 7 || research_id < 0 || !phone_book[research_id].isSet()){
                std::cout << "Invalid Id." << std::endl;
            }
            else{
                std::cout << "selected id : " << research_id<< std::endl;
                phone_book[research_id].display();
            }
        }
        else if (input == "FILL"){

            phone_book[i++].setContact("titi", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");

            phone_book[i++].setContact("tata", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");

            phone_book[i++].setContact("toto", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
            phone_book[i++].setContact("tutu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
            phone_book[i++].setContact("flo", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
            phone_book[i++].setContact("malo", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
            phone_book[i++].setContact("mathieu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
            phone_book[i++].setContact("jududu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
        }
        else{
            std::cout << "Command must be one of the following : 'EXIT', 'SEARCH' or 'ADD'." << std::endl;
        }
        std::cin.clear();
    }

    return 0;
}