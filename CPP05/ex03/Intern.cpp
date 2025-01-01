/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:25:43 by mayan             #+#    #+#             */
/*   Updated: 2024/12/31 21:26:21 by mayan            ###   ########.fr       */
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

AForm* Intern::makeForm(std::string const& formName, std::string const& target)
{
    std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* forms[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formNames[i] << " form" << std::endl;
            return forms[i];
        }
        else
        {
            delete forms[i];
        }
    }
    std::cout << "Intern can't create " << formName << " form not found :(" << std::endl;
    return NULL;
}

