#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
	Character *moi = new Character("moi");

	std::cout << *moi;

	Enemy *b = new RadScorpion();
	AWeapon *pr = new PlasmaRifle();
	AWeapon *pf = new PowerFist();

	moi->equip(pr);
	std::cout << *moi;
	moi->equip(pf);
	moi->attack(b);
	std::cout << *moi;
	moi->equip(pr);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;
	moi->attack(b);
	std::cout << *moi;

	std::cout << std::endl;

	Enemy *c = new SuperMutant();

	moi->equip(pf);
	moi->attack(c);
	std::cout << c->getType() << " HP : "  << c->getHP() << std::endl;
	moi->attack(c);
	moi->attack(c);
	moi->attack(c);
	moi->attack(c);
	moi->attack(c);
	moi->attack(c);
	moi->attack(c);
	std::cout << *moi;
	moi->recoverAP();
	moi->recoverAP();
	moi->recoverAP();
	moi->recoverAP();
	moi->recoverAP();
	std::cout << *moi;
	moi->attack(c);
	moi->attack(c);

	return 0;
}