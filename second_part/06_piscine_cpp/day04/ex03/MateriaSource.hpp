#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

public:

	MateriaSource(void);
	~MateriaSource(void);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const & type);

	unsigned int	getNbUnits() const;


private:

	typedef struct s_memory {
		AMateria 	*materia;
		s_memory 	*next;
	}				t_memory;

	t_memory	*_inv;

	unsigned int _nbUnits;


};

#endif
