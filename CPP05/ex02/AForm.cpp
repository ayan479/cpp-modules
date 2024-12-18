/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:02:03 by mayan             #+#    #+#             */
/*   Updated: 2024/12/16 20:48:06 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradetosign(150), _gradetoexec(150) {}

Form::Form(const Form& ref) : _name(ref._name), _signed(ref._signed), _gradetosign(ref._gradetosign), _gradetoexec(ref._gradetoexec) {}

Form::Form(std::string const name, int gradetosign, int gradetoexec) : _name(name), _signed(false), _gradetosign(gradetosign), _gradetoexec(gradetoexec)
{
    if (gradetosign < 1 || gradetoexec < 1)
        throw Form::GradeTooHighException();
    if (gradetosign > 150 || gradetoexec > 150)
        throw Form::GradeTooLowException();
}

Form::~Form() {}

Form& Form::operator=(const Form& ref)
{
    if (this != &ref)
    {
        _signed = ref._signed;
    }
    return *this;
}

std::string const Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

int Form::getGradeToSign() const
{
    return _gradetosign;
}

int Form::getGradeToExec() const
{
    return _gradetoexec;
}

void Form::beSigned(Bureaucrat const& b)
{
    if (b.getGrade() <= _gradetosign)
        _signed = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, Form const& ref)
{
    os << "Form " << ref.getName() << " is ";
    if (ref.isSigned())
        os << GREEN <<"signed" << RESET;
    else
        os << RED <<"not signed" << RESET;
    os << " and requires grade " << CYAN <<ref.getGradeToSign() << RESET <<" to sign and grade "<< RESET << CYAN << ref.getGradeToExec() << RESET <<" to execute";
    return os;
}