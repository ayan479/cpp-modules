/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:25:53 by mayan             #+#    #+#             */
/*   Updated: 2025/01/09 15:29:10 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
    private:
        typedef AForm* (Intern::*FormCreator)(std::string const& target);//typedef ReturnType (*AliasName)(ParameterType1, ...);
        AForm* createPresidentialPardonForm(std::string const& target);
        AForm* createRobotomyRequestForm(std::string const& target);
        AForm* createShrubberyCreationForm(std::string const& target);
    
    public:
        Intern();
        Intern(const Intern&);
        ~Intern();

        Intern& operator=(const Intern&);

        AForm* makeForm(std::string const& formName, std::string const& target);
};

// Custom Data Type: FormCreator is essentially a new "type" that represents:
// -A member function of the Intern class.
// -This member function returns a pointer to an AForm object.
// -It takes a single parameter: a constant reference to a std::string.