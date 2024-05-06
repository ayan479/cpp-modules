/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 20:02:11 by mayan             #+#    #+#             */
/*   Updated: 2024/05/04 20:09:24 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

#define BLUE "\033[34m"		// Blue
#define GREEN "\033[32m"	// Green
#define RED "\033[31m"		// Red
#define YELLOW "\033[33m"	// Yellow
#define CYAN "\033[36m"		// Cyan
#define RESET "\033[0m"		// Reset
#define BOLD "\033[1m"		// Bold


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

#endif