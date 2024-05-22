/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:32:14 by mayan             #+#    #+#             */
/*   Updated: 2024/05/16 21:43:27 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include	<cmath>

class Fixed {
	private:
		int _value;
		static const int _Bits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &object);
		~Fixed();
		Fixed &operator=(const Fixed &rhs);
		Fixed operator+(const Fixed &rhs) const;
		Fixed operator-(const Fixed &rhs) const;
		Fixed operator*(const Fixed &rhs) const;
		Fixed operator/(const Fixed &rhs) const;

		Fixed &operator++();
		Fixed &operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		bool operator>(const Fixed &rhs) const;
		bool operator<(const Fixed &rhs) const;
		bool operator>=(const Fixed &rhs) const;
		bool operator<=(const Fixed &rhs) const;
		bool operator==(const Fixed &rhs) const;
		bool operator!=(const Fixed &rhs) const;

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &object);

#endif

/**Concept:

Fixed-point numbers dedicate a fixed number of bits to the integer part and a
fixed number of bits to the fractional part of a number.
The decimal point (or binary point for computers) remains in a fixed position.
Visual Representation:

+----------+-----------+ (Total bits)
| Integer | Fractional |
+----------+-----------+
The number of bits allocated for each part determines the range and precision of the representable values.
Example (8-bit fixed-point):

Let's say we have 8 bits (total) for a fixed-point number.
We might allocate 5 bits for the integer part and 3 bits for the fractional part.
**Integer | Fractional|	Representable value**
	00000		.	000					0 (integer)
	00000		.	001					0.125 (binary point after the first 0)
	00000		.	111					0.875 (maximum fractional value with 3 bits)
	00001		.	000					1 (integer)*/