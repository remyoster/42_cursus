#ifndef FACTORY_H
# define FACTORY_H

# include "IOperand.hpp"

class Factory
{
public:
	Factory(void);
	~Factory(void);

	IOperand const *createOperand(eOperandType type, std::string const &value) const;
	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;
	
};

#endif
