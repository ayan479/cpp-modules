/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:24 by mayan             #+#    #+#             */
/*   Updated: 2024/12/25 16:55:24 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string> //strings
#include <exception> // std::exception
#include "AForm.hpp"

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

class AForm;

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
		void				signForm(AForm &f);
		void				executeForm(AForm const & form);
		

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
