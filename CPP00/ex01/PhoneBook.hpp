/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:04:25 by mayan             #+#    #+#             */
/*   Updated: 2024/05/04 19:55:03 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Contact.hpp"

#define BLUE "\033[34m"		// Blue
#define GREEN "\033[32m"	// Green
#define RED "\033[31m"		// Red
#define YELLOW "\033[33m"	// Yellow
#define CYAN "\033[36m"		// Cyan
#define RESET "\033[0m"		// Reset
#define BOLD "\033[1m"		// Bold

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