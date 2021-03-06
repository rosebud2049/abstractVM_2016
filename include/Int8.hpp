//
// Int8.hpp for abstractVM in /media/gmardon/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/guillaume.mardon/delivery/abstractVM_2016/include
//
// Made by guillaume.mardon@epitech.eu
// Login   <guillaume.mardon@epitech.eu>
//
// Started on  Fri Jul 20 3:05:36 PM 2017 guillaume.mardon@epitech.eu
// Last update Sat Jul 21 11:20:58 AM 2017 guillaume.mardon@epitech.eu
//
#ifndef _INT8_HPP_
#define _INT8_HPP_
#include "Operand.hpp"

class Int8 : public Operand<int8_t>
{
public:
    Int8(const std::string & value);
    ~Int8();
};

template <>
int Operand<int8_t>::getPrecision() const
{
	return 0;
}

template <>
eOperandType Operand<int8_t>::getType() const
{
	return INT8;
}
#endif