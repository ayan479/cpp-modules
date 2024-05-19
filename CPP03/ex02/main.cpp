/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:32:07 by mayan             #+#    #+#             */
/*   Updated: 2024/05/19 20:50:07 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap test1("Jack");
	ScavTrap test("Black");
	FragTrap test2("White");

	std::cout << std::endl;
	test1.attack("Drake");
	test1.takeDamage(10);
	test1.beRepaired(10);
	test.attack("Baka");
	test.takeDamage(15);
	test.beRepaired(15);
	std::cout << std::endl;

	std::cout << std::endl;
	test2.attack("Drizzy");
	std::cout << std::endl;
	test2.takeDamage(5);
	std::cout << std::endl;
	test2.beRepaired(5);
	std::cout << std::endl;
	test.guardGate();
	test2.highFivesGuys();
	std::cout << std::endl;
	return (0);
}

// int	main(void)
// {
// 	ScavTrap test("Jack Black");
// 	test.attack("Enemy 1");
// 	test.attack("Enemy 2");
// 	test.takeDamage(3);
// 	test.takeDamage(-1);
// 	test.beRepaired(-5);
// 	test.takeDamage(5);

// 	test.takeDamage(9);
// 	test.attack("Enemy 4");
// 	test.attack("Enemy 5");
// 	test.beRepaired(1);
// 	test.takeDamage(11);
// 	test.attack("Enemy 6");
// 	return (0);
// }