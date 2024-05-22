/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:17:15 by mayan             #+#    #+#             */
/*   Updated: 2024/05/16 21:50:51 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// int	main(void)
// {
// 	Fixed a(1);
// 	Fixed const b(Fixed(5.05f) * Fixed(2));
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a + 1 << std::endl;
// 	std::cout << a.toFloat() << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max(a, b) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "MinMax Test" << std::endl;
// 	Fixed a1( Fixed( 2 ) );
// 	std::cout << "max("<< a << " & " << b << ")" << " : " << Fixed::max( a, b ) << std::endl;
// 	std::cout << "min("<< a1 << " & " << a << ")" << " : " << Fixed::min( a1, a ) << std::endl;
// 	std::cout << std::endl;


// 	std::cout << "Arithmetic test" << std::endl;
// 	Fixed n1 = 150, n2 = 5.7f, n3 = 2.5f;
// 	// std::cout << n2 + n3 << std::endl;
// 	std::cout  << n1 << " + " << n2 << " + " << n3 << " = " << (n1 + n2 + n3) << std::endl
// 			   << n1 << " - " << n2 << " - " << n3 << " = " << (n1 - n2 - n3) << std::endl
// 			   << n1 << " * " << n2 << " * " << n3 << " = " << (n1 * n2 * n3) << std::endl
// 			   << n1 << " / " << n2 << " / " << n3 << " = " << (n1 / n2 / n3) << std::endl;
// 	std::cout << std::endl;


// 	std::cout << "Comparison test" << std::endl;
// 	n1 = 5, n2 = 10;
// 	std::cout << n1 << " > " << n2 << " = " << std::boolalpha << (n1 > n2) << std::endl;
// 	std::cout << n1 << " < " << n2 << " = " << std::boolalpha << (n1 < n2) << std::endl;
// 	std::cout << n1 << " >= " << n2 << " = " << std::boolalpha << (n1 >= n2) << std::endl;
// 	std::cout << n1 << " <= " << n2 << " = " << std::boolalpha << (n1 <= n2) << std::endl;
// 	std::cout << n1 << " == " << n2 << " = " << std::boolalpha << (n1 == n2) << std::endl;
// 	std::cout << n1 << " != " << n2 << " = " << std::boolalpha << (n1 != n2) << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "Increment test" << std::endl;
// 	Fixed num = 10;
// 	std::cout << "num = " << num << std::endl
// 			  << "num++ = " << num++ << std::endl
// 			  << "num = " << num << std::endl
// 			  << "++num = " << ++num << std::endl;

// 	std::cout << "\nDecrement Tests" << std::endl
// 			  << "num = " << num << std::endl
// 			  << "num-- = " << num-- << std::endl
// 			  << "num = " << num << std::endl
// 			  << "--num = " << --num << std::endl;
// 	return (0);
// }

//  where performance is sometimes more important then precision.
//  Fixed point arithmetic is much faster and therefore better than floating point arithmetic
