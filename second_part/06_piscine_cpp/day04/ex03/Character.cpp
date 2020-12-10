#include <iostream>
#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _inv(NULL), _equiped(0) {}

Character::Character(Character const &src) : _name(src.getName()), _inv(NULL), _equiped(0)
{
	*this = src;
}

Character::~Character(void)
{
	this->_deleteInv();
}

Character &Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		this->_deleteInv();
		for (int i = 0; i < rhs.getEquiped(); i++)
			this->equip(rhs.getMateria(i)->clone());
	}
	return (*this);
}

void Character::unequip(int idx)
{
	t_inventory *head = this->_inv;
	t_inventory *prev = NULL;

	if (idx >= 0 && idx < this->getEquiped())
	{
		if (idx == 0) {
			this->_inv = head->next;
			head->materia = NULL;
			delete head;
		}
		else {
			while (idx--) {
				prev = head;
				head = head->next;
			}
			prev->next = head->next;
			head->materia = NULL;
			delete head;
		}
		this->_equiped -= 1;
	}
}

void Character::equip(AMateria *m)
{
	t_inventory *head = this->_inv;

	if (this->getEquiped() < 4 && m)
	{
		t_inventory *tmp = new t_inventory;
		tmp->materia = m;
		tmp->next = NULL;
		if (!this->_inv)
			this->_inv = tmp;
		else
		{
			while (head->next)
				head = head->next;
			head->next = tmp;
		}
		this->_equiped += 1;
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < this->getEquiped())
		this->getMateria(idx)->use(target);
}

void Character::_deleteInv()
{
	t_inventory *head = this->_inv;
	t_inventory *tmp;

	while (head)
	{
		tmp = head->next;
		delete head->materia;
		head->materia = NULL;
		delete head;
		head = tmp;
	}
	this->_inv = NULL;
	this->_equiped = 0;
}

AMateria *Character::getMateria(int idx) const
{
	t_inventory *head = this->_inv;

	while (idx--)
		head = head->next;
	return (head->materia);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

int Character::getEquiped() const
{
	return (this->_equiped);
}