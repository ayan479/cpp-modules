/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:54:48 by mayan             #+#    #+#             */
/*   Updated: 2024/05/05 22:46:23 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

const std::string &Contact::get_first_name()
{
	return (first_name);
}

const std::string &Contact::get_last_name()
{
	return (last_name);
}

const std::string &Contact::get_nickname()
{
	return (nickname);
}

const std::string &Contact::get_phone_number()
{
	return (phone_number);
}

const std::string &Contact::get_darkest_secret()
{
	return (darkest_secret);
}

bool isNumber(const std::string &str)
{
    size_t i = 0;
    while (i < str.size() && std::isdigit(str[i])) {
        ++i;
    }
    return i == str.size();
}

std::string validateInput(const std::string &message)
{
    std::string input;
    while (1) {
        std::cout << message;
        if (!std::getline(std::cin, input) || std::cin.eof())
            exit(1);
        if (!input.empty())
            return input;
        std::cout << RED <<"Input cannot be empty." << std::endl;
    }
}

void Contact::makecontact()
{
    first_name = validateInput(BLUE "Enter first name: " RESET);
    last_name = validateInput(BLUE "Enter last name: " RESET);
    nickname = validateInput(BLUE "Enter nickname: " RESET);
    while (1)
		{
        phone_number = validateInput(BLUE "Enter phone number: " RESET);
        if (isNumber(phone_number))
            break;
        std::cout << RED << "Invalid phone number. Please enter a number." << std::endl;
    }
    darkest_secret = validateInput(BLUE "Enter darkest secret: " RESET);
}
