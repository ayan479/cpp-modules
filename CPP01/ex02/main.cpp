/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:51:25 by mayan             #+#    #+#             */
/*   Updated: 2024/05/13 20:19:56 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Address of the stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of the stringREF: " << &stringREF << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl;
}

// +----+-----+ (memory)
// | num | 10  |
// +----+-----+
//        |
//        v (ptr)
// +----+-----+
// | ptr |  ... | (memory address of num)
// +----+-----+

// +----+-----+ (memory)
// | num | 10  |
// +----+-----+
//        |
//        v (ref) (same memory location as num)

// Feature					Pointer																						Reference
// Memory Address	Stores the memory address of another variable			Does not store an address, directly refers to it
// Initialization	Can be null																				Must be initialized with an existing variable
// Reassignment		Can be reassigned to point to different locations	Cannot be reassigned after initialization
// Usage	More 		flexible (null checks, pointer arithmetic)				Safer (avoids dangling pointers), simpler to use

// Use pointers for dynamic memory allocation (heap), null checks, and complex memory manipulations.
// Use references for function arguments (passing by reference), avoiding unnecessary copying, and improving readability.