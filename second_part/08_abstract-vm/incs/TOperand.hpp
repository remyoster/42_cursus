#ifndef TOPERAND_H
# define TOPERAND_H

# include "IOperand.hpp"
# include "Factory.hpp"
# include "Error.hpp"
# include <cstdlib>
# include <cmath>
# include <string>  
# include <limits>

/*
** Template Operand class which implementes IOperand interface. It just needs
** a eOperandType to know which type to use.
*/

template <enum eOperandType E, typename T = double>
class TOperand : public IOperand
{
public:
	TOperand<E, T>(std::string const & value) : _type(E), _value(value) {
		double d = std::stod(value);
		if (d < std::numeric_limits<T>::lowest())
			throw (Error::Underflow(E, value));
		else if (d > std::numeric_limits<T>::max())
			throw (Error::Overflow(E, value));
		this->_typedVal = static_cast<T>(d);
	}

	virtual int getPrecision(void) const {
		return (this->_type);
	}						

	virtual eOperandType getType(void) const {
		return (this->_type);
	}

	virtual IOperand const *operator+(IOperand const &rhs) const {
		const std::string newValue = this->to_string_with_precision(
			this->_typedVal + std::stod(rhs.toString()),
			this->higherPrecision(rhs)
			);
		return (this->_factory.createOperand(this->higherType(rhs), newValue));
	}

	virtual IOperand const *operator-(IOperand const &rhs) const {
		const std::string newValue = this->to_string_with_precision(
			this->_typedVal - std::stod(rhs.toString()),
			this->higherPrecision(rhs)
			);
		return (this->_factory.createOperand(this->higherType(rhs), newValue));

	};
	virtual IOperand const *operator*(IOperand const &rhs) const {
		const std::string newValue = this->to_string_with_precision(
			this->_typedVal * std::stod(rhs.toString()),
			this->higherPrecision(rhs)
			);
		return (this->_factory.createOperand(this->higherType(rhs), newValue));

	}
	virtual IOperand const *operator/(IOperand const &rhs) const {
		const std::string newValue = this->to_string_with_precision(
			this->_typedVal / std::stod(rhs.toString()),
			this->higherPrecision(rhs)
			);
		return (this->_factory.createOperand(this->higherType(rhs), newValue));

	}
	virtual IOperand const *operator%(IOperand const &rhs) const {
		const std::string newValue = this->to_string_with_precision(
			fmod(this->_typedVal, std::stod(rhs.toString())),
			this->higherPrecision(rhs)
			);
		return (this->_factory.createOperand(this->higherType(rhs), newValue));

	}
	virtual std::string const &toString(void) const {
		return (this->_value);
	}

	eOperandType higherType(IOperand const &rhs) const {
		return (rhs.getType() > this->_type ? rhs.getType() : this->_type);
	}

	size_t higherPrecision(IOperand const &rhs) const {
		size_t found = this->_value.find('.');
		if (found == std::string::npos)
				found = 0;
		size_t found2 = rhs.toString().find('.');
		return (found2 != std::string::npos && found2 > found ? found2 : found);
	}

	std::string to_string_with_precision(const double val, const size_t n) const
	{
		std::ostringstream out;
		out.precision(n);
		out << std::fixed << val;
		return (out.str());
	}

	virtual ~TOperand(void) {}

private:
	eOperandType		_type;
	std::string			_value;
	Factory				_factory;
	T					_typedVal;
};

#endif
