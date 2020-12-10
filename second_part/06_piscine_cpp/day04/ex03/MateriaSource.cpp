#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _inv(NULL), _nbUnits(0) {}

MateriaSource::~MateriaSource(void) {
	t_memory *head = this->_inv;
	t_memory *tmp;

	while (head) {
		delete head->materia;
		head->materia = NULL;
		tmp = head->next;
		delete head;
		head = tmp;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	t_memory *head = this->_inv;

	if (this->getNbUnits() < 4 && m)
	{
		t_memory *tmp = new t_memory;
		tmp->materia = m;
		tmp->next = NULL;
		if (!head)
			this->_inv = tmp;
		else
		{
			while (head->next)
				head = head->next;
			head->next = tmp;
		}
		this->_nbUnits += 1;
	}
}

AMateria *MateriaSource::createMateria(std::string const & type) {
	t_memory *head = this->_inv;

	while (head) {
		if (head->materia->getType().compare(type) == 0)
			return (head->materia->clone());
		head = head->next;
	}
	return (0);
}

unsigned int MateriaSource::getNbUnits() const
{
	return (this->_nbUnits);
}