//
// Created by MaSit on 22/02/2021.
//

#ifndef OLD_CPP_MODULES_CONTACT_HPP
# define OLD_CPP_MODULES_CONTACT_HPP

#include <iostream>

class contact {
public:
    contact(void);
    ~contact(void);
    void setContact(std::string first_name, std::string last_name,std::string nickname,std::string login,std::string postal_address,
    std::string email_address,std::string phone_number,std::string birthday_date,std::string favorite_meal,
    std::string underwear_color,std::string darkest_secret);
    void display();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    bool isSet();
private:
    bool        _set;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _login;
    std::string _postal_address;
    std::string _email_address;
    std::string _phone_number;
    std::string _birthday_date;
    std::string _favorite_meal;
    std::string _underwear_color;
    std::string _darkest_secret;

};


#endif //OLD_CPP_MODULES_CONTACT_HPP
