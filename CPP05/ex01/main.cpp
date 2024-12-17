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
#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat b1("John",2);
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
    try
    {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;

        Form f2("Form2", 150, 100);
        std::cout << f2 << std::endl;

        b2.signForm(f2);
        std::cout << f2 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cerr << "Caught exception!: " << e.what() << std::endl;
    }
    
    try
    {
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}