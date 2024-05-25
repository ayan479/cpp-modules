/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 20:13:05 by mayan             #+#    #+#             */
/*   Updated: 2024/05/24 22:51:34 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &object) : WrongAnimal(object)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = object;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Mroeeeeoooooowng~🐱❌" << std::endl;
}
