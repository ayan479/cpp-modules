/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 20:43:04 by mayan             #+#    #+#             */
/*   Updated: 2024/05/13 20:34:39 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int		main()
{
	Harl harl;

	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	return 0;
}

// int main(int ac, char **av)
// {
// 	if (argc != 2) {
// 		std::cout << "Arg Error\n";
// 		return 1;
// 	}

// 	std::string	level = argv[1];
// 	Harl harl;

// 	harl.complain("error");
// 	return 0;
// }