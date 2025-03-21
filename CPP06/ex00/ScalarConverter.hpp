/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:56:48 by mayan             #+#    #+#             */
/*   Updated: 2025/03/19 22:35:51 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
#include <cstdlib>

class ScalarConverter
{
    private: //prevent instantiation
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter&);

        static void handleChar(char c);
        static void handleFloat(float f);
        static void handleDouble(double d);
        static void handleInt(int i);
        static bool specialFloat(std::string const &str);
        static bool specialDouble(std::string const &str);
        
    public:
        static void convert(std::string const &str);
};

