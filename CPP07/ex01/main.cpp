/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 03:55:54 by mayan             #+#    #+#             */
/*   Updated: 2025/04/12 22:05:42 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
    int Integers[] = {0, 1, 2, 3, 4};
    std::cout << GREEN << "Original integers: " << RESET << std::endl;
    iter(Integers, 5, print<int>); //instantiation of print<int> function
    
    std::cout << GREEN << "Incremented integers: " << RESET << std::endl;
    iter(Integers, 5, increment<int>);
    iter(Integers, 5, print<int>);
    
    char Characters[] = "Hello";
    std::cout << GREEN << "Original characters: " << RESET << std::endl;
    iter(Characters, 5, print<char>);
    
    std::cout << GREEN << "Incremented characters: " << RESET << std::endl;
    iter(Characters, 5, increment<char>);
    iter(Characters, 5, print<char>);
    
    return 0;
}
