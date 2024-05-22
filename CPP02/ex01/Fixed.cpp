/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:14:01 by mayan             #+#    #+#             */
/*   Updated: 2024/05/16 21:43:27 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
	: _value(value << this->_Bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
	: _value(roundf(value * (1 << this->_Bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed &object)
{
	out << object.toFloat();
	return (out);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_value / (1 << this->_Bits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_Bits);
}

// Floating-Point to Fixed-Point Conversion:

// Multiply 42.42 by 256 to get 10844.32. _value(roundf(value * (1 << this->_Bits)))
// Round 10844.32 to 10844. _value(roundf(value * (1 << this->_Bits)))
// Binary representation of 10844 is 10101001101100.
// Fixed-Point Representation:

// Place the decimal point 8 bits from the right: 00101010.01101100.
// Fixed-Point to Floating-Point Conversion:

// Integer part: 42.
// Fractional part: 0.421875.
// Combined: 42.421875.