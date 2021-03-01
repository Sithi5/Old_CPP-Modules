#include <iostream>
#include "contact.hpp"
#include "sstream"

void print_with_width(std::string str, int width){
    std::cout.width(width);
    std::cout << str;
    return ;
}

void print_formated_contact_info(std::string str){
    if (str.size() >= 10){
        str.resize(9);
        str.append(".");
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

        std::getline(std::cin ,input);
        if (input == "EXIT"){
            break;
        }
        else if (input == "ADD"){
            if (phone_book[7].isSet()){
                std::cout << "Your phonebook is full !" << std::endl;
                continue;
            }

            std::string input_string[11] = {
                    "first name",
                    "last name",
                    "nickname",
                    "login",
                    "postal_address",
                    "email_address",
                    "phone_number",
                    "birthday_date",
                    "favorite_meal",
                    "underwear_color",
                    "darkest_secret"
            };
            std::string input[11];

            for (int i = 0 ; i < 11; ++i){
                  std::cout << input_string[i] << ": " << std::endl;
                  std::cout << "input: ";
                  std::getline(std::cin, input[i]);
            }

            phone_book[i].setContact(input[0], input[1], input[2], input[3], input[4], input[5], input[6], input[7], input[8], input[9], input[10]);
            std::cout << "Contact " << input[0] << " has been created with the following info : " << std::endl;
            phone_book[i++].display();
        }
        else if (input == "SEARCH"){
            int research_id = -1;
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
                }
            }

            std::cout << "Which contact do you want to display ? " << std::endl;
            std::getline(std::cin, input);
            std::stringstream ss(input);
            if ((ss >> research_id).fail()){
                research_id = -1;
            }
            std::cout << "id = " << research_id <<std::endl;
            if (research_id > 7 || research_id < 0 || !phone_book[research_id].isSet()){
                std::cout << "Invalid Id." << std::endl;
            }
            else{
                std::cout << "selected id : " << research_id<< std::endl;
                phone_book[research_id].display();
            }
        }
//        else if (input == "FILL"){
//            phone_book[i++].setContact("tititititi", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("ratatatatatatatatatatatatatata", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("toto", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("MINET", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("flo", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("malo", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("mathieu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//            phone_book[i++].setContact("jududu", "t", "t", "t", "t", "t", "t", "t", "t", "t", "t");
//        }
        else{
            std::cout << "Command must be one of the following : 'EXIT', 'SEARCH' or 'ADD'." << std::endl;
        }
        std::cin.clear();
    }

    return 0;
}