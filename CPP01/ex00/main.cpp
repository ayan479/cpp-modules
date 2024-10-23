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

/**
 * @file main.cpp
 * @brief Entry point for the Zombie application.
 *
 * This file contains the main function which demonstrates the creation and
 * announcement of Zombie objects. It creates a Zombie object dynamically,
 * makes it announce itself, and then deletes it. Additionally, it calls
 * a function to create and announce a Zombie object on the stack.
 *
 * @details
 * - `newZombie`: Creates a Zombie object dynamically.
 * - `announce`: Makes the Zombie object announce itself.
 * - `randomChump`: Creates a Zombie object on the stack and makes it announce itself.
 * - `delete`: Frees the dynamically allocated Zombie object.
 *
 * @return int Returns 0 upon successful execution.
 */
int main()
{
		Zombie *zombie = newZombie("Foo");
		zombie->announce();
		randomChump("Bar");
		delete zombie;
		return 0;
}

// we use new to allocate memory for a new Zombie object and return a pointer to it