/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:42:56 by mayan             #+#    #+#             */
/*   Updated: 2024/05/19 20:51:04 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << GREEN <<"FragTrap is here! (default constructor called)"<< RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN <<"FragTrap " << this->_name << " is here! (name constructor called)"<< RESET << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &object) : ClapTrap(object)
{
	std::cout << "FragTrap is being copied" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED <<"FragTrap is being destroyed! NOOOOOOOOOOOOOOOOO" << RESET <<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return (*this);
}

void FragTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		std::cout << YELLOW <<"FragTrap " << this->_name << " throws a grenade at " << target << ", causin " << this->_attackDamage << " points of damage!" << RESET << std::endl;
		_energyPoints--;
	}
	else
		std::cout << RED <<"FragTrap " << this->_name << " cant attack " << target << ". Its all outta juice (No energy/hit points left)!" << RESET << std::endl;
}

void FragTrap::highFivesGuys(void)
{
		std::cout << GREEN <<"FragTrap " << this->_name << ": any high fives guys!? 🙋" << RESET << std::endl;
}