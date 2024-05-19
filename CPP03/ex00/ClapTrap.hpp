/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:20:12 by mayan             #+#    #+#             */
/*   Updated: 2024/05/18 21:34:45 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
	ClapTrap();
	ClapTrap(const ClapTrap &object);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &rhs);

	ClapTrap(std::string name);
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif


// ---BASE CLASS---|				|-----------DERIVED CLASS---------------------------|
// Data members	 	|------------>  _______________________											|
// Function members|				|				|Base Class Sub-object|											|
// ----------------|       |				|---------------------|											|
// 												|       |Data members	        |										  |
// 												|			  |Function members     |										  |
// 												|    		|---------------------|										  |
// 												|...................................................|
// 												|				|Derived Class Data members|								|
// 												|				|Derived Class Function members|						|
// 												|---------------------------------------------------|

