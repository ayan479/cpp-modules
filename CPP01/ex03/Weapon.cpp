/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:08:19 by mayan             #+#    #+#             */
/*   Updated: 2024/05/12 18:15:21 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::~Weapon() {
}

const std::string &Weapon::getType()
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}