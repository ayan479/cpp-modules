/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 21:32:07 by mayan             #+#    #+#             */
/*   Updated: 2024/05/18 22:25:23 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// int main()
// {
// 	ClapTrap claptrap("joe");
// 	ClapTrap claptrap2;
// 	ClapTrap claptrap3(claptrap);


// 	claptrap.attack("Skag");
// 	claptrap.takeDamage(5);
// 	claptrap.beRepaired(3);
// 	claptrap2.attack("Skago");
// 	claptrap2.takeDamage(20);
// 	claptrap2.beRepaired(3);
// 	claptrap3.attack("Skagoo");
// 	claptrap3.takeDamage(2);
// 	claptrap3.beRepaired(3000000);
// 	claptrap3.attack("Skagoo");
// 	claptrap3.takeDamage(99999999);

// 	return (0);
// }

int	main(void)
{
	ClapTrap test("Jack Black");
	test.attack("Enemy 1");
	test.attack("Enemy 2");
	test.takeDamage(3);
	test.attack("Enemy 3");
	test.takeDamage(2);
	test.beRepaired(5);
	test.takeDamage(-1);
	test.beRepaired(-5);
	test.takeDamage(5);

	test.takeDamage(9);
	test.attack("Enemy 4");
	test.attack("Enemy 5");
	test.beRepaired(1);
	test.takeDamage(11);
	test.attack("Enemy 6");
	return (0);
}