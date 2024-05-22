/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:48:40 by mayan             #+#    #+#             */
/*   Updated: 2024/05/12 02:48:40 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) : _name(name) {
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead." << std::endl;
}
void Zombie::announce() {
	std::cout << this->_name << ": Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

