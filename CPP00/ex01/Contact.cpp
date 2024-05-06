/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:54:48 by mayan             #+#    #+#             */
/*   Updated: 2024/05/06 15:05:37 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
    : first_name(""),
      last_name(""),
      nickname(""),
      phone_number(""),
      darkest_secret("")
{
}

Contact::~Contact()
{
}

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

void Contact::set_first_name(const std::string &fname)
{
    first_name = fname;
}

void Contact::set_last_name(const std::string &lname)
{
    last_name = lname;
}

void Contact::set_nickname(const std::string &nn)
{
    nickname = nn;
}

void Contact::set_phone_number(const std::string &phone)
{
    phone_number = phone;
}

void Contact::set_darkest_secret(const std::string &secret)
{
    darkest_secret = secret;
}

int isNumber(const std::string &str)
{
    size_t i = 0;
		while (i < str.length())
		{
				if (!std::isdigit(str[i]))
						return (0);
				i++;
		}
		return (1);
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
    set_first_name(validateInput(BLUE "Enter first name: " RESET));
    set_last_name(validateInput(BLUE "Enter last name: " RESET));
    set_nickname(validateInput(BLUE "Enter nickname: " RESET));

    while (1) {
        std::string phone = validateInput(BLUE "Enter phone number: " RESET);
        if (isNumber(phone)) {
            set_phone_number(phone);
            break;
        } else {
            std::cout << RED << "Invalid phone number. Please enter a number." << std::endl;
        }
    }

    set_darkest_secret(validateInput(BLUE "Enter darkest secret: " RESET));
}