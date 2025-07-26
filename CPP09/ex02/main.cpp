/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:00 by mayan             #+#    #+#             */
/*   Updated: 2025/01/17 00:00:00 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	try {
		PmergeMe sorter(argc, argv);
		sorter.sort();
	}
	catch (std::exception& e) {
		std::cerr << RED << "Error" << RESET << std::endl;
		return 1;
	}
	
	return 0;
}
