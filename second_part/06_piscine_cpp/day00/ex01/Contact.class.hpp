#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>

class Contact {

public:

	Contact(void);
	~Contact(void);

	int			setAttr(char const *attr, char const *val);
	std::string	getAttr(char const *attr) const;

	static int	getNbInst(void);

private:

	char		_firstname[255];
	char		_lastname[255];
	char		_phone_number[255];
	char		_nickname[255];
	char		_login[255];
	char		_postal[255];
	char		_address[255];
	char		_email[255];
	char		_birthday_date[255];
	char		_favorite_meal[255];
	char		_underwear_color[255];
	char		_darkest_secret[255];


	static int	_nbInst;
};

#endif