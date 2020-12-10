#ifndef PONY_H
# define PONY_H

class Pony {

public:

	Pony(char const *name);
	~Pony(void);

	char const	*name;

	void	snort(void) const;
	void	walk(void) const;
	void	stop(void) const;

	static int	getNbInst(void);

private:

	static int	_nbInst;

};

#endif
