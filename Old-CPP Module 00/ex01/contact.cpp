#include "contact.hpp"

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
	setFirstName(first_name);
	setLastName(last_name);
	setNickname(nickname);
	setLogin(login);
	setPostalAddress(postal_address);
	setEmailAddress(email_address);
	setPhoneNumber(phone_number);
	setBirthdayDate(birthday_date);
	setFavoriteMeal(favorite_meal);
	setUnderwearColor(underwear_color);
	setDarkestSecret(darkest_secret);
	this->_set = 1;
}

void Contact::display()
{
	if (this->isSet())
	{
		std::cout << "first_name = " << getFirstName() << std::endl;
		std::cout << "last_name = " << getLastName() << std::endl;
		std::cout << "login = " << getLogin() << std::endl;
		std::cout << "postal_address = " << getPostalAddress() << std::endl;
		std::cout << "email_address = " << getEmailAddress() << std::endl;
		std::cout << "phone_number = " << getPhoneNumber() << std::endl;
		std::cout << "birthday_date = " << getBirthdayDate() << std::endl;
		std::cout << "favorite_meal = " << getFavoriteMeal() << std::endl;
		std::cout << "underwear_color = " << getUnderwearColor() << std::endl;
		std::cout << "darkest_secret = " << getDarkestSecret() << std::endl;
	}
}

bool Contact::isSet() { return this->_set; }

void Contact::setFirstName(std::string first_name) { this->_first_name = first_name; }
void Contact::setLastName(std::string last_name) { this->_last_name = last_name; }
void Contact::setNickname(std::string _nickname) { this->_nickname = _nickname; }
void Contact::setLogin(std::string login) { this->_login = login; }
void Contact::setPostalAddress(std::string postal_address) { this->_postal_address = postal_address; }
void Contact::setEmailAddress(std::string email_address) { this->_email_address = email_address; }
void Contact::setPhoneNumber(std::string phone_number) { this->_phone_number = phone_number; }
void Contact::setBirthdayDate(std::string birthday_date) { this->_birthday_date = birthday_date; }
void Contact::setFavoriteMeal(std::string favorite_meal) { this->_favorite_meal = favorite_meal; }
void Contact::setUnderwearColor(std::string underwear_color) { this->_underwear_color = underwear_color; }
void Contact::setDarkestSecret(std::string darkest_secret) { this->_darkest_secret = darkest_secret; }

std::string Contact::getFirstName() { return (this->_first_name); }
std::string Contact::getLastName() { return (this->_last_name); }
std::string Contact::getNickname() { return (this->_nickname); }
std::string Contact::getLogin() { return (this->_login); }
std::string Contact::getPostalAddress() { return (this->_postal_address); }
std::string Contact::getEmailAddress() { return (this->_email_address); }
std::string Contact::getPhoneNumber() { return (this->_phone_number); }
std::string Contact::getBirthdayDate() { return (this->_birthday_date); }
std::string Contact::getFavoriteMeal() { return (this->_favorite_meal); }
std::string Contact::getUnderwearColor() { return (this->_underwear_color); }
std::string Contact::getDarkestSecret() { return (this->_darkest_secret); }
