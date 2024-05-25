/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:18:34 by mayan             #+#    #+#             */
/*   Updated: 2024/05/24 22:28:17 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &object) : Animal(object), _brain(new Brain(*object._brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	delete _brain;
	_brain = new Brain(*rhs._brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meeeeoooooow~🐱" << std::endl;
}

Brain *Cat::getBrain() const
{
	return (this->_brain);
}
