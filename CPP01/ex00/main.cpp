/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:30:10 by mayan             #+#    #+#             */
/*   Updated: 2024/05/10 14:27:52 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
		Zombie *zombie = newZombie("Zombie1");
		zombie->announce();
		randomChump("Zombie2");
		delete zombie;
		return (0);
}