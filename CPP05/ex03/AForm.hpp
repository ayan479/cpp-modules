/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:14:43 by mayan             #+#    #+#             */
/*   Updated: 2024/12/16 20:00:56 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradetosign;//grade required to sign the form
        int const _gradetoexec;//grade required to execute the form
        
    public:
        AForm();
        AForm(const AForm&);
        AForm(std::string const name, int gradetosign, int gradetoexec);//parametric
        virtual ~AForm();
        
        AForm& operator=(const AForm&);
        
        std::string const getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        void beSigned(Bureaucrat const&);//sign the form
        virtual void execute(Bureaucrat const& executor) const = 0;//pure virtual function
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, AForm const& ref);
