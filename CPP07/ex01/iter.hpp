/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 03:58:52 by mayan             #+#    #+#             */
/*   Updated: 2025/03/28 04:22:33 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#define GREEN "\033[32m"
#define RESET "\033[0m"

template <typename T, typename F>
void	iter(T *array, unsigned int length, F function)
{
    for (unsigned int i = 0; i < length; i++)
        function(array[i]);
}

template <typename T>
void    print(T const &thing)
{
    std::cout << thing << std::endl;
}

template <typename T>
void increment(T &thing)
{
    thing++;
}

// To compile iter(), it first needs to determine the concrete type of the third argument
// But print doesn't have a concrete type until you specify 
// which instantiation of the print template you want to use