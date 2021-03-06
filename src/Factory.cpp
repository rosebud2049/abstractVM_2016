//
// Factory.cpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/src
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Sat Jul 21 1:52:20 PM 2017 guillaume.mardon@epitech.eu
// Last update Thu Jul 26 3:35:15 PM 2017 guillaume.mardon@epitech.eu
//
#include "Factory.hpp"

Factory::Factory()
{
	operands_str["INT8"] = INT8;
	operands_str["INT16"] = INT16;
	operands_str["INT32"] = INT32;
	operands_str["FLOAT"] = FLOAT;
	operands_str["DOUBLE"] = DOUBLE;
	operands_str["BIGDECIMAL"] = BIGDECIMAL;
	operands[INT8] = &Factory::createInt8;
	operands[INT16] = &Factory::createInt16;
	operands[INT32] = &Factory::createInt32;
	operands[FLOAT] = &Factory::createFloat;
	operands[DOUBLE] = &Factory::createDouble;
	operands[BIGDECIMAL] = &Factory::createBigDecimal;
}

IOperand const* Factory::createOperand(eOperandType type, std::string const& value) const
{
	IOperand const* (Factory::*f)(std::string const & value) const;
	f = operands.at(type);
	return ((*this.*f)(value));
}

IOperand const* Factory::createOperand(std::string type, std::string const& value) const
{
	std::transform(type.begin(), type.end(), type.begin(), ::toupper);
	if (operands_str.find(type) == operands_str.end())
		throw Exception("Cannot resolve type !");
	return this->createOperand(operands_str.find(type)->second, value);
} 

IOperand const* Factory::createInt8( std::string const & value ) const
{
	return (new Int8(value));
}

IOperand const* Factory::createInt16( std::string const & value ) const
{
	return (new Int16(value));
}

IOperand const* Factory::createInt32( std::string const & value ) const
{
	return (new Int32(value));
}

IOperand const* Factory::createFloat( std::string const & value ) const
{
	return (new Float(value));
}

IOperand const* Factory::createDouble( std::string const & value ) const
{
	return (new Double(value));
}

IOperand const* Factory::createBigDecimal( std::string const & value ) const
{
	return (new BigDecimal(value));
}

Factory::~Factory()
{

}