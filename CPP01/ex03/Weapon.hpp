/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:07:06 by mayan             #+#    #+#             */
/*   Updated: 2024/05/12 18:16:18 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class WEAPON
{
	private:
		std::string _type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		const std::string &getType();
		void setType(std::string type);
};

#endif

