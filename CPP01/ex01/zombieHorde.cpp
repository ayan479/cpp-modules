/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 16:25:54 by mayan             #+#    #+#             */
/*   Updated: 2024/05/12 16:49:48 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];

	if (N < 0)
		return NULL;
	for (int i = 0; i < N; i++)
	{
		zombies[i].setName(name);
		zombies[i].announce();
	}
	return zombies;
}
