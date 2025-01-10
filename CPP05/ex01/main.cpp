/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:04:26 by mayan             #+#    #+#             */
/*   Updated: 2025/01/02 18:04:35 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Test Case 1: Valid Bureaucrat and Form Creation
    std::cout << YELLOW << "Test Case 1: Valid Bureaucrat and Form Creation" << RESET << std::endl;
    try
    {
        Bureaucrat b1("John", 2);
        std::cout << b1 << std::endl;
        
        Form f1("Form1", 1, 1);
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception!: " << e.what() << std::endl;
    }
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Test Case 2: Invalid Form Creation
    std::cout << YELLOW << "Test Case 2: Invalid Form Creation" << RESET << std::endl;
    try
    {
        Form f2("InvalidFormHigh", 0, 50); // Should throw GradeTooHighException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception!: " << e.what() << std::endl;
    }

    try
    {
        Form f3("InvalidFormLow", 50, 151); // Should throw GradeTooLowException
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception!: " << e.what() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Test Case 3: Signing Forms
    std::cout << YELLOW << "Test Case 3: Signing Forms" << RESET << std::endl;
    try
    {
        Bureaucrat b4("Alice", 50);
        Form f4("Form4", 100, 100);
        std::cout << b4 << std::endl;
        std::cout << f4 << std::endl;

        b4.signForm(f4); // Should throw GradeTooLowException
        std::cout << f4 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception!: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b5("Bob", 100);
        Form f5("Form5", 100, 100);
        std::cout << b5 << std::endl;
        std::cout << f5 << std::endl;

        b5.signForm(f5); // Should succeed
        std::cout << f5 << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception!: " << e.what() << std::endl;
    }
}
