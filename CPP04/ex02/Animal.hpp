/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:28:43 by mayan             #+#    #+#             */
/*   Updated: 2024/05/25 18:24:22 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

#define BLUE "\033[34m"		// Blue
#define GREEN "\033[32m"	// Green
#define RED "\033[31m"		// Red
#define YELLOW "\033[33m"	// Yellow
#define CYAN "\033[36m"		// Cyan
#define RESET "\033[0m"		// Reset
#define BOLD "\033[1m"		// Bold

class Animal
{
	protected:
		std::string	_type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &object);
		virtual ~Animal();
		Animal &operator=(const Animal &rhs);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif
// Pure Virtual Functions and Abstract Classes
// A pure virtual function is a function that has no implementation in the base class and must be overridden in derived classes.
// Declaring a pure virtual function makes a class abstract, meaning you cannot instantiate objects of that class.

// in contrast, Concrete refers to classes that are fully implemented and can be instantiated to create objects. These classes provide
// concrete implementations for all their methods, including any inherited abstract methods from parent classes.



// The virtual keyword in C++ is used to declare a method in a base class
// that can be overridden by derived classes. It ensures that the correct method is called for an object,
// regardless of the type of reference (or pointer) used for the call, enabling runtime polymorphism.

/* Polymorphism
The word means having many forms. It is the ability of a message(function / operator) to be displayed in more than one form. In C++, an operator or function can be given different meanings or functions.

In C++, polymorphism is mainly divided into two types:

Compile time polymorphism (early binding / static polymorphism) - static in nature
This includes function overloading and operator overloading.
It is resolved at compile time.
No virtual keyword is needed.

Runtime polymorphism (late binding / dynamic polymorphism)
This is achieved through inheritance and virtual functions.
It is resolved at runtime.
The virtual keyword is essential to enable this form of polymorphism.
*/


