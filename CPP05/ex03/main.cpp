/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:28 by mayan             #+#    #+#             */
/*   Updated: 2024/12/31 21:14:17 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testForm(AForm &form, Bureaucrat &bureaucrat)
{
    try
    {
        form.beSigned(bureaucrat);
        form.execute(bureaucrat);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    // Test Case Intern 
    std::cout << YELLOW << "Test Case 1: Intern creates RobotomyRequestForm" << RESET << std::endl;
    try
    {
        Intern intern;
        AForm *form = intern.makeForm("robotomy request", "Bender");
        Bureaucrat bureaucrat("Bureaucrat", 1);
        testForm(*form, bureaucrat);
        delete form;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;

    std::cout << YELLOW << "Test Case 2: Intern creates ShrubberyCreationForm" << RESET << std::endl;
    try
    {
        Intern intern;
        AForm *form = intern.makeForm("shrubbery creation", "Garden");
        Bureaucrat bureaucrat("Bureaucrat", 1);
        testForm(*form, bureaucrat);
        delete form;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;

    std::cout << YELLOW << "Test Case 3: Intern creates PresidentialPardonForm" << RESET << std::endl;
    try
    {
        Intern intern;
        AForm *form = intern.makeForm("presidential pardon", "Arthur Dent");
        Bureaucrat bureaucrat("Bureaucrat", 1);
        testForm(*form, bureaucrat);
        delete form;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << YELLOW << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << RESET << std::endl;

    std::cout << YELLOW << "Test Case 4: Intern with invalid form name" << RESET << std::endl;
    try
    {
        Intern intern;
        AForm *form = intern.makeForm("invalid form", "Target");
        if (form)
        {
            Bureaucrat bureaucrat("Bureaucrat", 1);
            testForm(*form, bureaucrat);
            delete form;
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}