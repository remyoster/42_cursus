#include <iostream>
#include <string.h>
#include "Contact.class.hpp"

int Contact::_nbInst = 0;

Contact::Contact(void)
{
	Contact::_nbInst += 1;
	return ;
}

Contact::~Contact(void)
{
	Contact::_nbInst -= 1;
	return;
}

int		Contact::setAttr(char const *attr, char const *val)
{
	std::string s (attr);
	if (s.length() == 0 || s.length() > 254) {
		return (-1);
	}
	if (s.compare("firstname") == 0)
		strcpy(this->_firstname, val);
	else if (s.compare("lastname") == 0)
		strcpy(this->_lastname, val);
	else if (s.compare("nickname") == 0)
		strcpy(this->_nickname, val);
	else if (s.compare("login") == 0)
		strcpy(this->_login, val);
	else if (s.compare("postal") == 0)
		strcpy(this->_postal, val);
	else if (s.compare("address") == 0)
		strcpy(this->_address, val);
	else if (s.compare("email") == 0)
		strcpy(this->_email, val);
	else if (s.compare("phone_number") == 0)
		strcpy(this->_phone_number, val);
	else if (s.compare("birthday_date") == 0)
		strcpy(this->_birthday_date, val);
	else if (s.compare("favorite_meal") == 0)
		strcpy(this->_favorite_meal, val);
	else if (s.compare("underwear_color") == 0)
		strcpy(this->_underwear_color, val);
	else if (s.compare("darkest_secret") == 0)
		strcpy(this->_darkest_secret, val);
	else
		return (-1);
	return (1);
}

std::string	Contact::getAttr(char const *attr) const
{
	std::string s (attr);
	if (s.compare("firstname") == 0)
		return this->_firstname;
	else if (s.compare("lastname") == 0)
		return this->_lastname;
	else if (s.compare("nickname") == 0)
		return this->_nickname;
	else if (s.compare("login") == 0)
		return this->_login;
	else if (s.compare("postal") == 0)
		return this->_postal;
	else if (s.compare("address") == 0)
		return this->_address;
	else if (s.compare("email") == 0)
		return this->_email;
	else if (s.compare("phone_number") == 0)
		return this->_phone_number;
	else if (s.compare("birthday_date") == 0)
		return this->_birthday_date;
	else if (s.compare("favorite_meal") == 0)
		return this->_favorite_meal;
	else if (s.compare("underwear_color") == 0)
		return this->_underwear_color;
	else if (s.compare("darkest_secret") == 0)
		return this->_darkest_secret;
	else
		return (NULL);
}

int	Contact::getNbInst(void)
{
	return Contact::_nbInst;
}
