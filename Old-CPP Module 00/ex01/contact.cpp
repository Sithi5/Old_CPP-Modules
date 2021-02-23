#include "Contact.hpp"

Contact::Contact(void) : _set(0)
{
}

Contact::~Contact()
{
}

void Contact::setContact(std::string first_name, std::string last_name, std::string nickname, std::string login, std::string postal_address,
						 std::string email_address, std::string phone_number, std::string birthday_date, std::string favorite_meal,
						 std::string underwear_color, std::string darkest_secret)
{
	this->_first_name = first_name;
	this->_last_name = last_name;
	this->_nickname = nickname;
	this->_login = login;
	this->_postal_address = postal_address;
	this->_email_address = email_address;
	this->_phone_number = phone_number;
	this->_birthday_date = birthday_date;
	this->_favorite_meal = favorite_meal;
	this->_underwear_color = underwear_color;
	this->_darkest_secret = darkest_secret;
	this->_set = 1;
}

void Contact::display()
{
	if (this->isSet())
	{
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

bool Contact::isSet()
{
	return this->_set;
}

void Contact::setFirstName(std::string first_name) { this->_first_name = first_name; }
void Contact::setLastName(std::string last_name) { this->_last_name = last_name; }
void Contact::setNickname(std::string _nickname) { this->_first_name = _nickname; }
void Contact::setLogin(std::string login) { this->_login = login; }
void Contact::setPostalAddress(std::string postal_address) { this->_postal_address = postal_address; }
void Contact::setEmailAddress(std::string email_address) { this->_email_address = email_address; }
void Contact::setPhoneNumber(std::string phone_number) { this->_phone_number = phone_number; }
void Contact::setBirthdayDate(std::string birthday_date) { this->_birthday_date = birthday_date; }
void Contact::setFavoriteMeal(std::string favorite_meal) { this->_favorite_meal = favorite_meal; }
void Contact::setUnderwearColor(std::string underwear_color) { this->_underwear_color = underwear_color; }
void Contact::setDarkestSecret(std::string darkest_secret) { this->_darkest_secret = darkest_secret; }

std::string Contact::getFirstName()
{
	return (this->_first_name);
}

std::string Contact::getLastName() { return (this->_last_name); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getNickname() { return (this->_nickname); }
