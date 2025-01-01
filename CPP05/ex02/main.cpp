/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:52:28 by mayan             #+#    #+#             */
/*   Updated: 2024/12/28 20:21:04 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    // Test Case 1: Valid Form Creation and Execution
    std::cout << YELLOW << "Test Case 1: Valid Form Creation and Execution" << RESET << std::endl;
    try
    {
        Bureaucrat b1("John", 1);
        std::cout << b1 << std::endl;

        ShrubberyCreationForm f1("home");
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        b1.executeForm(f1);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Test Case 2: Form Execution Without Signing
    std::cout << YELLOW << "Test Case 2: Form Execution Without Signing" << RESET << std::endl;
    try
    {
        Bureaucrat b2("Jane", 1);
        std::cout << b2 << std::endl;

        ShrubberyCreationForm f2("garden");
        std::cout << f2 << std::endl;

        b2.executeForm(f2); // Should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Test Case 3: Form Execution with Insufficient Grade
    std::cout << YELLOW << "Test Case 3: Form Execution with Insufficient Grade" << RESET << std::endl;
    try
    {
        Bureaucrat b3("Alice", 150);
        std::cout << b3 << std::endl;

        ShrubberyCreationForm f3("park");
        std::cout << f3 << std::endl;

        b3.signForm(f3); // Should throw an exception
        b3.executeForm(f3); // Should not reach here
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Test Case 4: Form Signing with Insufficient Grade
    std::cout << YELLOW << "Test Case 4: Form Signing with Insufficient Grade" << RESET << std::endl;
    try
    {
        Bureaucrat b4("Bob", 150);
        std::cout << b4 << std::endl;

        ShrubberyCreationForm f4("office");
        std::cout << f4 << std::endl;

        b4.signForm(f4); // Should throw an exception
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Test Case 5: RobotomyRequestForm Execution
    std::cout << YELLOW << "Test Case 5: RobotomyRequestForm Execution" << RESET << std::endl;
    try
    {
        Bureaucrat b5("John", 44);
        std::cout << b5 << std::endl;

        RobotomyRequestForm f5("WALL-E");
        std::cout << f5 << std::endl;

        b5.signForm(f5);
        b5.executeForm(f5);
        b5.executeForm(f5);
        b5.executeForm(f5);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

    // Test Case 6: PresidentialPardonForm Execution
    std::cout << YELLOW << "Test Case 6: PresidentialPardonForm Execution" << RESET << std::endl;
    try
    {
        Bureaucrat b6("John", 1);
        std::cout << b6 << std::endl;

        PresidentialPardonForm f6("Arthur Dent");
        std::cout << f6 << std::endl;

        b6.signForm(f6);
        b6.executeForm(f6);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}