/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:24 by mayan             #+#    #+#             */
/*   Updated: 2024/06/27 21:08:51 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string> // std::string
#include <exception> // std::exception

class Bureaucrat
{
		private:
				std::string const   _name;
				int                 _grade;

		public:
				Bureaucrat();
				Bureaucrat(std::string const name, int grade);
				
