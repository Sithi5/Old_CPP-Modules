#include "contact.hpp"

contact::contact(void): _set(0){
    std::cout << "A contact have been created." << std::endl;
}

contact::~contact(){
}

void contact::setContact(std::string first_name, std::string last_name,std::string nickname,std::string login,std::string postal_address,
std::string email_address,std::string phone_number,std::string birthday_date,std::string favorite_meal,
std::string underwear_color,std::string darkest_secret){
    this->_first_name = first_name;
    this->_last_name = last_name;
    this->_nickname = nickname;
    this->_login = login;
    this->_postal_address=postal_address;
    this->_email_address=email_address;
    this->_phone_number=phone_number;
    this->_birthday_date=birthday_date;
    this->_favorite_meal=favorite_meal;
    this->_underwear_color=underwear_color;
    this->_darkest_secret=darkest_secret;
    this->_set = 1;
}

void contact::display(){
    if (this->isSet()){
        std::cout << "first_name = " << this->_first_name << std::endl;
        std::cout << "last_name = " << this->_last_name << std::endl;
        std::cout << "login = " << this->_login << std::endl;
        std::cout << "postal_address = " << this->_postal_address << std::endl;
        std::cout << "email_address = " << this->_email_address << std::endl;
        std::cout << "phone_number = " << this->_phone_number << std::endl;
        std::cout << "birthday_date = " << this->_birthday_date << std::endl;
        std::cout << "favorite_meal = " << this->_favorite_meal << std::endl;
        std::cout << "underwear_color = " << this->_underwear_color << std::endl;
        std::cout << "darkest_secret = " << this->_darkest_secret << std::endl;
    }
}

bool contact::isSet() {
    return this->_set;
}

std::string contact::getFirstName(){
    return this->_first_name;
}
std::string contact::getLastName(){
    return this->_last_name;
}
std::string contact::getNickname(){
    return this->_nickname;
}
