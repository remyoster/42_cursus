#include <iostream>
#include <iomanip> // std::setw
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) : _nbContact(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::listenToPrompt(void)
{
	std::string s;
	while (1)
	{
		std::getline(std::cin, s);
		if (s.compare("ADD") == 0)
			this->add();
		else if (s.compare("SEARCH") == 0)
			this->search();
		else if (s.compare("HELP") == 0)
		{
			std::cout << "You can type the following :" << std::endl;
			std::cout << "- ADD => add a new contact" << std::endl;
			std::cout << "- SEARCH => search a contact" << std::endl;
			std::cout << "- EXIT => close the program" << std::endl;
			std::cout << "- HELP => display this helper" << std::endl;
		}
		else if (s.compare("EXIT") == 0)
			return;
		else {
			std::cout << "Error : " << s << " is not a valid command. ";
			std::cout << "Type HELP to see available commands" << std::endl;
		}
	}
}

void PhoneBook::add(void)
{
	std::string s;
	size_t idx;

	idx = 0;
	if (this->_nbContact >= 8)
	{
		std::cout << "Too much contact, sorry you can't add more..." << std::endl;
		return;
	}
	std::cout << "You're going to add a new contact" << std::endl;
	while (idx < 12)
	{
		std::cout << this->get_entries(idx) << " : ";
		std::getline(std::cin, s);
		if (s.length() > 0) {
		this->_contact[this->_nbContact].setAttr(
			this->get_entries(idx).c_str(), s.c_str());
		idx++;
		}
		else
			std::cout << "Invalid input, retry" << std::endl;
		
	}
	this->_nbContact += 1;
	std::cout << "All fields are completed ! What do you want to do now ?";
	std::cout << std::endl;
	return;
}

void PhoneBook::search(void) const
{
	int idx;
	std::string buff;

	if (this->_nbContact == 0)
	{
		std::cout << "You need to add some contact before searching them.";
		std::cout << " Type ADD" << std::endl;
		return;
	}
	std::cout << std::setw(11);
	std::cout << "index|";
	std::cout << std::setw(11);
	std::cout << "firstname|";
	std::cout << std::setw(11);
	std::cout << "lastname|";
	std::cout << std::setw(11);
	std::cout << "nickname|";
	std::cout << std::endl;
	idx = 0;
	while (idx < this->_nbContact)
	{
		print_basic(this->_contact[idx], idx);
		idx++;
	}
	std::cout << std::endl << "Type any index number : ";
	std::getline(std::cin, buff);
	if (buff.length() > 1 || (int)buff[0] - 48 > this->_nbContact)
		std::cout << "Error in index, you're back to main prompt" << std::endl;
	else if (buff.length() > 0)
		print_full(this->_contact[(int)buff[0] - 48]);
	return;
}

void PhoneBook::print_basic(Contact contact, int index) const
{
	size_t idx;
	std::string s;

	std::cout << std::setw(10);
	std::cout << index << "|";
	idx = 0;
	while (idx < 3)
	{
		std::cout << std::setw(10);
		s = contact.getAttr(this->get_entries(idx).c_str());
		if (s.length() > 10)
		{
			s.resize(9);
			s += ".";
		}
		std::cout << s << "|";
		idx++;
	}
	std::cout << std::endl;
}

void PhoneBook::print_full(Contact contact) const
{
	size_t idx;

	idx = 0;
	while (idx < 12)
	{
		std::cout << this->get_entries(idx) << " : ";
		std::cout << contact.getAttr(this->get_entries(idx).c_str());
		std::cout << std::endl;
		idx++;
	}
	return;
}

std::string PhoneBook::get_entries(size_t idx) const
{
	char entries[12][50] = {
		{"firstname"},
		{"lastname"},
		{"phone_number"},
		{"nickname"},
		{"login"},
		{"postal"},
		{"address"},
		{"email"},
		{"birthday_date"},
		{"favorite_meal"},
		{"underwear_color"},
		{"darkest_secret"}};
	return (std::string(entries[idx]));
}