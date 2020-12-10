#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *moi = new Character("moi");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	moi->equip(tmp);
	tmp = src->createMateria("cure");
	moi->equip(tmp);

	ICharacter *bob = new Character("bob");
	moi->use(0, *bob);
	moi->use(1, *bob);

	delete bob;
	delete moi;
	delete src;

	std::cout << std::endl;

	moi = new Character("moi");
	bob = new Character("bob");
	src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	moi->equip(src->createMateria("cure"));
	moi->equip(src->createMateria("ice"));
	moi->equip(src->createMateria("cure"));
	moi->equip(src->createMateria("ice"));
	moi->equip(src->createMateria("ice"));
	moi->equip(src->createMateria("WTF"));
	moi->equip(src->createMateria("LOL"));

	moi->use(2, *bob);
	moi->use(3, *bob);
	moi->use(0, *bob);
	moi->use(-2, *bob);
	moi->unequip(1);
	moi->unequip(0);
	moi->use(2, *bob);
	moi->use(3, *bob);
	moi->unequip(4);
	moi->unequip(-8);
	moi->unequip(3);
	moi->unequip(2);
	moi->unequip(1);
	moi->unequip(0);

	tmp = src->createMateria("ice");

	delete bob;
	Character *james = new Character("james");
	james->equip(tmp);
	james->unequip(0);
	james->equip(tmp);
	bob = new Character(*james);

	bob->use(0, *james);
	bob->use(1, *moi);

	delete bob;
	delete moi;
	delete james;
	delete src;

	return 0;
}