/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:24 by mayan             #+#    #+#             */
/*   Updated: 2025/01/02 15:43:32 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string> //strings
#include <exception> // std::exception
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

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

				class GradeTooHighException : public std::exception//we are inheriting from std::exception and creating our own exception class as a nested class of Bureaucrat 
				{
					public:
						virtual const char* what() const throw();//overriding the what() function of std::exception, virtual is not part of the signature of the function, it is just a keyword to tell the compiler that this function can be overridden in a derived class
				};

				class GradeTooLowException : public std::exception
				{
					public:
						virtual const char* what() const throw();
				};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& ref);

#endif
