/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 22:14:01 by mayan             #+#    #+#             */
/*   Updated: 2024/05/16 22:46:56 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _value(0)
{
}

Fixed::Fixed(const Fixed &object)
{
	*this = object;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int value)
	: _value(value << this->_Bits)
{
}

Fixed::Fixed(const float value)
	: _value(roundf(value * (1 << this->_Bits)))
{
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

/////Arithmetic operators

Fixed Fixed::operator+(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

/////Increment and Decrement operators

Fixed &Fixed::operator++()
{
	this->_value = this->_value + 1;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->_value = this->_value - 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

/////Comparison operators

bool Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs.getRawBits());
}

/////Min and Max functions

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

// Floating-Point to Fixed-Point Conversion:

// Multiply 42.42 by 256 to get 10844.32.
// Round 10844.32 to 10844.
// Binary representation of 10844 is 101010.01101100.
// Fixed-Point Representation:

// Place the decimal point 8 bits from the right: 00101010.01101100.
// Fixed-Point to Floating-Point Conversion:

// Integer part: 42.
// Fractional part: 0.421875.
// Combined: 42.421875.