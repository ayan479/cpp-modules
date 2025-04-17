/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 03:32:27 by mayan             #+#    #+#             */
/*   Updated: 2025/04/17 15:52:22 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>

// container: vector, list, array, etc.
// value: int to find
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("val not found in the container");
    return it;
}

// Each container implements iterators that know how to navigate its specific structure:
// Vector iterators: Jump directly (like pointer arithmetic)
// List iterators: Follow link pointers
// Map iterators: Traverse tree structure

//standardised way of accessing containers data, allows for them to work with any algorithm 
