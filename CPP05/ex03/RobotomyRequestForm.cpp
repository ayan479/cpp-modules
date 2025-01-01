/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 18:39:40 by mayan             #+#    #+#             */
/*   Updated: 2024/12/25 19:47:44 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    srand(time(NULL));//seeding the random number generator
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    srand(time(NULL));//seeding the random number generator
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {
    srand(time(NULL));//seeding the random number generator
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
        AForm::operator=(rhs);
        _target = rhs._target;
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > getGradeToExec())
        throw AForm::GradeTooLowException();
    if (!isSigned())
    {
        std::cout << "Form is not signed" << std::endl;
        return ;
    }

    std::cout<< CYAN << "*DRILLING NOISES*" << RESET <<std::endl;
    if (rand() % 2)
        std::cout<< GREEN << _target << " has been robotomized successfully" << RESET <<std::endl;
    else
        std::cout<< RED << "Robotomization of " << _target << " has failed" << RESET <<std::endl;
}

