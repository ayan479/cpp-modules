/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:56:45 by mayan             #+#    #+#             */
/*   Updated: 2025/03/21 18:12:30 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) { *this = src; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    (void)src;
    return *this;
}

bool ScalarConverter::specialFloat(std::string const &str)
{
    if (str == "nanf" || str == "+inff" || str == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << std::endl;
        std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
        return true;
    }
    return false;
}

bool ScalarConverter::specialDouble(std::string const &str)
{
    if (str == "nan" || str == "+inf" || str == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << str << "f" << std::endl;
        std::cout << "double: " << str << std::endl;
        return true;
    }
    return false;
}

// You have to first detect the type of the literal passed as parameter,
// convert it from string to its actual type, 
// then convert it explicitly to the three other data types.
void ScalarConverter::convert(std::string const &str)
{
    if (str.empty())
    {
        std::cout << "Empty String" << std::endl;
        return;
    }
    if (specialFloat(str) || specialDouble(str))
        return;
    if (str.length() == 1 && !isdigit(str[0]))
    {
        handleChar(str[0]);
        return;
    }
    
    try
    {
        char *endptr;
        //check if float
        if (str[str.length() - 1] == 'f')
        {
            float f = strtof(str.c_str(), &endptr);
            if (*endptr != 'f' || *(endptr + 1) != '\0')
                throw std::invalid_argument("Invalid argument");
            handleFloat(f);
            return;
        }
        if (str.find('.') != std::string::npos) //check if double
        {
            double d = std::strtod(str.c_str(), &endptr);
            if (*endptr != '\0')
                throw std::invalid_argument("Invalid argument");
            handleDouble(d);
            return;
        }
        else //has to b int
        {
            long i = std::strtol(str.c_str(), &endptr, 10);
            if (*endptr != '\0')
                throw std::invalid_argument("Invalid argument");
            if (i < INT_MIN || i > INT_MAX)
                throw std::invalid_argument("Invalid argument");
            handleInt(static_cast<int>(i));
        }  
    }
    catch (const std::exception &e)
    {
        std::cout << "Invalid Input" << std::endl;
    }
    
}

void ScalarConverter::handleChar(char c)
{
    std::cout << "char: ";
    if (isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::handleFloat(float f)
{
    std::cout << "char: ";
    if (f >= 0 && f <= 127)
    {    
        if (isprint(static_cast<char>(f)))
            std::cout << "'" << static_cast<char>(f) << "'";
        else
            std::cout << "Non displayable";
    }
    else
        std::cout << "impossible";
    std::cout << std::endl;

    std::cout << "int: ";
    if (f >= INT_MIN && f <= INT_MAX)
        std::cout << static_cast<int>(f);
    else
        std::cout << "impossible";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::handleDouble(double d)
{
    std::cout << "char: ";
    if (d >= 0 && d <= 127)
    {    
        if (isprint(static_cast<char>(d)))
            std::cout << "'" << static_cast<char>(d) << "'";
        else
            std::cout << "Non displayable";
    }
    else
        std::cout << "impossible";
    std::cout << std::endl;

    std::cout << "int: ";
    if (d >= INT_MIN && d <= INT_MAX)
        std::cout << static_cast<int>(d);
    else
        std::cout << "impossible";
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::handleInt(int i)
{
    std::cout << "char: ";
    if (i >= 0 && i <= 127)
    {    
        if (isprint(i))
            std::cout << "'" << static_cast<char>(i) << "'";
        else
            std::cout << "Non displayable";
    }
    else
        std::cout << "impossible";
    std::cout << std::endl;

    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

