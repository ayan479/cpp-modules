/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:20:12 by mayan             #+#    #+#             */
/*   Updated: 2024/05/19 19:07:33 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#define BLUE "\033[34m"		// Blue
#define GREEN "\033[32m"	// Green
#define RED "\033[31m"		// Red
#define YELLOW "\033[33m"	// Yellow
#define CYAN "\033[36m"		// Cyan
#define RESET "\033[0m"		// Reset
#define BOLD "\033[1m"		// Bold


class ClapTrap
{
	protected:
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

