/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:42:56 by mayan             #+#    #+#             */
/*   Updated: 2024/05/19 20:27:36 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << GREEN <<"ScavTrap default constructor called"<< RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN <<"ScavTrap name constructor called"<< RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &object) : ClapTrap(object)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED <<"ScavTrap destructor called" << RESET <<std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void ScavTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << GREEN <<"ScavTrap " << this->_name << " attacks " << target << ", causin " << this->_attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	}
	else
		std::cout << RED <<"ScavTrap " << this->_name << " can not attack " << target << ". No energy/hit points left!" << RESET << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << BLUE <<"ScavTrap " << this->_name << " has entered into Gate keeper mode." << RESET << std::endl;
}
