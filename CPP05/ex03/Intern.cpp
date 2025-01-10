/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:25:43 by mayan             #+#    #+#             */
/*   Updated: 2025/01/10 19:13:27 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern & src) { *this = src; }

Intern::~Intern() {}

Intern & Intern::operator=(const Intern & src)
{ 
    (void)src; 
    return *this;
}

AForm* Intern::createPresidentialPardonForm(std::string const& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(std::string const& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreationForm(std::string const& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string const& formName, std::string const& target)
{
    std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    
    FormCreator creator[3] = {&Intern::createPresidentialPardonForm, &Intern::createRobotomyRequestForm, &Intern::createShrubberyCreationForm};
    
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (this->*creator[i])(target);
        }
    }
    
    std::cout << "Form " << RED << formName << RESET <<" not found." << std::endl;
    return NULL;
}

