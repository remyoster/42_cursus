#ifndef ENEMY_H
# define ENEMY_H

# include <iostream>

class Enemy {

public:

	Enemy(int hp, std::string const & type);
	virtual ~Enemy(void);

	Enemy &	operator=(Enemy const & rhs);

	std::string const getType() const;
	int getHP() const;
	virtual void takeDamage(int);

	void setHP(int hp);

private:
	Enemy(void);
	Enemy(Enemy const & src);
	int					_hp;
	std::string const	_type;

};

#endif
