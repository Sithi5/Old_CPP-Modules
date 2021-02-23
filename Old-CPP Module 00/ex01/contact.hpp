#ifndef OLD_CPP_MODULES_CONTACT_HPP
#define OLD_CPP_MODULES_CONTACT_HPP

#include <iostream>

class Contact
{
public:
    Contact(void);
    ~Contact(void);
    void setContact(std::string first_name, std::string last_name, std::string nickname, std::string login, std::string postal_address,
                    std::string email_address, std::string phone_number, std::string birthday_date, std::string favorite_meal,
                    std::string underwear_color, std::string darkest_secret);
    void display();
    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
    void setNickname(std::string nickname);
    void setLogin(std::string login);
    void setPostalAddress(std::string postal_address);
    void setEmailAddress(std::string email_address);
    void setPhoneNumber(std::string phone_number);
    void setBirthdayDate(std::string birthday_date);
    void setFavoriteMeal(std::string favorite_meal);
    void setUnderwearColor(std::string underwear_color);
    void setDarkestSecret(std::string darkest_secret);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getLogin();
    std::string getPostalAddress();
    std::string getEmailAddress();
    std::string getPhoneNumber();
    std::string getBirthdayDate();
    std::string getFavoriteMeal();
    std::string getUnderwearColor();
    std::string getDarkestSecret();
    bool isSet();

private:
    bool _set;
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
