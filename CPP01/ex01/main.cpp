/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:35:08 by mayan             #+#    #+#             */
/*   Updated: 2024/05/12 02:35:08 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
		Zombie *zombie = newZombie("Foo");
		zombie->announce();
		randomChump("Bar");
		delete zombie;
		return 0;
}

// we use new to allocate memory for a new Zombie object and return a pointer to it