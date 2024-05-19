/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:32:07 by mayan             #+#    #+#             */
/*   Updated: 2024/05/19 20:27:36 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap test1("Jack");
	ScavTrap test("Black");
	ScavTrap test2("White");

	ClapTrap *a = &test1;
	ClapTrap *b = &test;


	a->attack("Drake");
	std::cout << std::endl;
	a->takeDamage(10);
	std::cout << std::endl;
	a->beRepaired(10);
	std::cout << std::endl;


	b->attack("Baka");
	std::cout << std::endl;
	b->takeDamage(15);
	std::cout << std::endl;
	b->beRepaired(15);
	std::cout << std::endl;


	test2.attack("Drizzy");
	std::cout << std::endl;
	test2.takeDamage(5);
	std::cout << std::endl;
	test2.beRepaired(5);
	std::cout << std::endl;
	test2.guardGate();
	std::cout << std::endl;


	return 0;
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