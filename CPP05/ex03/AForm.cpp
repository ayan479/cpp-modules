/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:03 by mayan             #+#    #+#             */
/*   Updated: 2024/12/16 20:48:06 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradetosign(150), _gradetoexec(150) {}

AForm::AForm(const AForm& ref) : _name(ref._name), _signed(ref._signed), _gradetosign(ref._gradetosign), _gradetoexec(ref._gradetoexec) {}

AForm::AForm(std::string const name, int gradetosign, int gradetoexec) : _name(name), _signed(false), _gradetosign(gradetosign), _gradetoexec(gradetoexec)
{
    if (gradetosign < 1 || gradetoexec < 1)
        throw AForm::GradeTooHighException();
    if (gradetosign > 150 || gradetoexec > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& ref)
{
    if (this != &ref)
    {
        _signed = ref._signed;
    }
    return *this;
}

std::string const AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradetosign;
}

int AForm::getGradeToExec() const
{
    return _gradetoexec;
}

void AForm::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() <= _gradetosign)
        _signed = true;
    else
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, AForm const& ref)
{
    os << "AForm " << ref.getName() << " is ";
    if (ref.isSigned())
        os << GREEN <<"signed" << RESET;
    else
        os << RED <<"not signed" << RESET;
    os << " and requires grade " << CYAN <<ref.getGradeToSign() << RESET <<" to sign and grade "<< RESET << CYAN << ref.getGradeToExec() << RESET <<" to execute";
    return os;
}