/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:43:12 by mayan             #+#    #+#             */
/*   Updated: 2024/05/13 20:30:45 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*levels[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels_str[4] = {"debug", "info", "warning", "error"};

	size_t i = 0;

	while(level.compare(levels_str[i]) && i < 4)
		i++;
	switch (i)
	{
		case 0:
			(this->*levels[0])();
			break;
		case 1:
			(this->*levels[1])();
			break;
		case 2:
			(this->*levels[2])();
			break;
		case 3:
			(this->*levels[3])();
			break;
		default:
			std::cout << "Invalid level" << std::endl;
			break;
	}
}

