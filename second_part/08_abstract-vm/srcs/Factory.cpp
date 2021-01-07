#include "Factory.hpp"
#include "TOperand.hpp"

Factory::Factory(void) {}
Factory::~Factory(void) {}

IOperand const * Factory::createInt8( std::string const & value ) const {
	return (new TOperand<Int8, int8_t>(value));
}
IOperand const * Factory::createInt16( std::string const & value ) const {
	return (new TOperand<Int16, int16_t>(value));
}
IOperand const * Factory::createInt32( std::string const & value ) const {
	return (new TOperand<Int32, int32_t>(value));
}
IOperand const * Factory::createFloat( std::string const & value ) const {
	return (new TOperand<Float, float>(value));
}
IOperand const * Factory::createDouble( std::string const & value ) const {
	return (new TOperand<Double>(value));
}

IOperand const *Factory::createOperand(eOperandType type, std::string const & value) const {
	IOperand const *(Factory::*func[])(std::string const & value) const = {
		&Factory::createInt8,
		&Factory::createInt16,
		&Factory::createInt32,
		&Factory::createFloat,
		&Factory::createDouble
	};
	return ((this->*func[type])(value));
}
