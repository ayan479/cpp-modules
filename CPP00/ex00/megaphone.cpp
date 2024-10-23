/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:23:35 by mayan             #+#    #+#             */
/*   Updated: 2024/09/20 19:29:21 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/**
 * @file megaphone.cpp
 * @brief A simple program that converts input arguments to uppercase and prints them.
 *
 * This program takes command-line arguments and converts each character to uppercase.
 * If no arguments are provided, it prints a default message.
 *
 * @param ac The number of command-line arguments.
 * @param av The array of command-line arguments.
 * @return 0 on successful execution.
 */
int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
		}
		std::cout << std::endl;
		return (0);
	}
}