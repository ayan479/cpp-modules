/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:50:16 by mayan             #+#    #+#             */
/*   Updated: 2024/05/19 16:38:56 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &object)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = object;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
}

void ClapTrap::attack(std::string const &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints >= 5)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " can't attack " << target << ". No energy/hit points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (int(amount) < 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't take negative damage!" << std::endl;
		return ;
	}
	else if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
		_hitPoints = (amount > _hitPoints) ? 0 : _hitPoints - amount;
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (int(amount) < 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't be repaired with negative hit points!" << std::endl;
		return ;
	}
	else if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " is being repaired for " << amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
}



