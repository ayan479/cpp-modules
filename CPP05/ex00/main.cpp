/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+           */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:28 by mayan             #+#    #+#             */
/*   Updated: 2024/10/22 20:04:20 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    //Testing invalid grade
    try
    {
        Bureaucrat b("Invalid", 000); // Throws GradeTooHighException
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b3("InvalidLow", 151); // Throws GradeTooLowException
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    //Testing Increment and Decrement
    //increment
    try
    {
        Bureaucrat b1("John", 2);
        std::cout << b1 << std::endl;
        
        b1.incrementGrade();
        std::cout << b1 << std::endl;
        
        b1.incrementGrade(); // Throws GradeTooHighException    
    }
    catch (const Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Caught a GradeTooHighException: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
    //decrement
    try
    {
        Bureaucrat b2("Jane", 149);
        std::cout << b2 << std::endl;

        b2.decrementGrade(); 
        std::cout << b2 << std::endl;

        b2.decrementGrade(); // Throws GradeTooLowException
    }
    catch (const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Caught a GradeTooLowException: " << e.what() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}