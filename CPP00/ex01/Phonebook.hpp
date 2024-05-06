/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:04:25 by mayan             #+#    #+#             */
/*   Updated: 2024/05/03 17:08:10 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#define BLUE "\033[34m"		// Blue
#define GREEN "\033[32m"	// Green
#define RED "\033[31m"		// Red
#define YELLOW "\033[33m"	// Yellow
#define RESET "\033[0m"		// Reset


class Contact{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string	phone_number;
		std::string darkest_secret;

	public:
		const std::string &get_first_name();
		const std::string &get_last_name();
		const std::string &get_nickname();
		const std::string &get_phone_number();
		const std::string &get_darkest_secret();

		void makecontact();
};

class PhoneBook
{
	private:
		Contact contacts[8];
		int current_contact;
		void printwidthmanager(std::string str);
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void add_contact();
		void printtable();

};

#endif