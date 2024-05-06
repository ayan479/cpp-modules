/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:03:58 by mayan             #+#    #+#             */
/*   Updated: 2024/05/06 14:25:30 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string command;

	while (1)
	{
		std::cout << YELLOW << "░▒▓█▓▒░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█▓▒░" << std::endl;
		std::cout << "▒ ☎️      EPIC PHONEBOOK OF AWESOMENESS       📖 ▒" << std::endl;
		std::cout << "░▒▓█▓▒░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█░▒▓█▓▒░" << RESET << std::endl;
		std::cout << GREEN << "Commands: \n1. ADD\n2. SEARCH\n3. EXIT" << RESET << std::endl;
		std::cout << "Enter a command: ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
		{
			pb.add_contact();
			system("sleep 0.60 && clear");
		}
		else if (command == "SEARCH")
		{
			system("sleep 0.60 && clear");
			pb.printtable();
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << RED << "Invalid command" << RESET << std::endl;
			system("sleep 0.60 && clear");
		}
		std::cin.clear();
	}
}
