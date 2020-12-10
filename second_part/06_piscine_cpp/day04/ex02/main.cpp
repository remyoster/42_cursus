#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
	ISpaceMarine *bob = new TacticalMarine;
	ISpaceMarine *jim = new AssaultTerminator;
	ISquad *vlc = new Squad;
	ISquad *vlc2;
	Squad *vlc3 = new Squad;

	vlc->push(bob);
	vlc->push(jim);

	for (int i = 0; i < vlc->getCount(); ++i)
	{
		ISpaceMarine *cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc;

	std::cout << std::endl;

	bob = new TacticalMarine;
	jim = new AssaultTerminator;
	ISpaceMarine *roger = new TacticalMarine;
	ISpaceMarine *james = new AssaultTerminator;

	vlc3->push(bob);
	vlc3->push(jim);

	vlc2 = new Squad(*vlc3);
	delete vlc3;

	vlc2->push(roger);
	vlc2->push(james);

	for (int i = 0; i < vlc2->getCount(); ++i)
	{
		ISpaceMarine *cur = vlc2->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}
	delete vlc2;

	return 0;
}
