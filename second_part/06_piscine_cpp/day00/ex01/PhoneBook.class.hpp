#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include "Contact.class.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);

	void		listenToPrompt(void);
	void		add(void);
	void		search(void) const;
	void		print_basic(Contact contact, int idx) const;
	void		print_full(Contact contact) const;
	std::string get_entries(size_t idx) const;


private:

	int			_nbContact;
	Contact 	_contact[8];
};

#endif
