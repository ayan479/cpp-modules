/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:34:36 by mayan             #+#    #+#             */
/*   Updated: 2024/05/24 22:31:17 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &object) : Animal(object), _brain(new Brain(*object._brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	delete _brain;
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof woof~🐶" << std::endl;
}

Brain *Dog::getBrain() const
{
	return (this->_brain);
}
