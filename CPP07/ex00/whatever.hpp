/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 03:24:41 by mayan             #+#    #+#             */
/*   Updated: 2025/03/28 03:52:50 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T const& a, T const& b)
{
    return (a < b ? a : b);
}

template<typename T>
T max(T const& a, T const& b)
{
    return (a > b ? a : b);
}

