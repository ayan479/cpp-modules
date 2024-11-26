/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:24 by mayan             #+#    #+#             */
/*   Updated: 2024/10/23 22:24:59 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception> // std::exception

class Bureaucrat
{
		private:
				std::string const   _name;
				int                 _grade;

		public:
				Bureaucrat();//default constructor
				Bureaucrat(const Bureaucrat&);//copy constructor
				~Bureaucrat();//destructor
				Bureaucrat(std::string const name, int grade);//parametric constructor

				Bureaucrat& operator=(const Bureaucrat&);//assignation operator

				std::string const   getName() const;
				int                 getGrade() const;

				void                incrementGrade();
				void                decrementGrade();
				
};

#endif // BUREAUCRAT_HPP
