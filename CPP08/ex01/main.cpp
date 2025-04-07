/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 04:09:46 by mayan             #+#    #+#             */
/*   Updated: 2025/04/07 04:18:56 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <cstdlib>

int main()
{
    // Test from the subject
    std::cout << BLUE << "===== Subject Test =====" << RESET << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    
    // Test with many numbers
    std::cout << BLUE << "\n===== Test with 10,000 numbers =====" << RESET << std::endl;
    Span bigSpan(10000);
    
    // Add many numbers at once using addNumbers
    std::vector<int> manyNumbers;
    std::srand(time(NULL));
    for (int i = 0; i < 10000; i++)
        manyNumbers.push_back(std::rand() % 1000000);
    
    bigSpan.addNumbers(manyNumbers.begin(), manyNumbers.end());
    
    std::cout << "Shortest span among 10,000 numbers: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest span among 10,000 numbers: " << bigSpan.longestSpan() << std::endl;
    
    // Test exceptions
    std::cout << BLUE << "\n===== Exception Testing =====" << RESET << std::endl;
    
    // Test adding too many numbers
    Span smallSpan(3);
    std::cout << YELLOW << "Adding too many numbers:" << RESET << std::endl;
    try
    {
        smallSpan.addNumber(1);
        smallSpan.addNumber(2);
        smallSpan.addNumber(3);
        smallSpan.addNumber(4); // This should throw an exception
    }
    catch(const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Test finding spans with not enough numbers
    Span emptySpan(5);
    std::cout << YELLOW << "Finding spans with not enough numbers:" << RESET << std::endl;
    try
    {
        emptySpan.shortestSpan(); // This should throw an exception
    }
    catch(const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    // Test adding a range that would exceed capacity
    std::cout << YELLOW << "Adding a range that exceeds capacity:" << RESET << std::endl;
    Span tinySpan(3);
    std::vector<int> tooManyNumbers;
    tooManyNumbers.push_back(1);
    tooManyNumbers.push_back(2);
    tooManyNumbers.push_back(3);
    tooManyNumbers.push_back(4);
    
    try
    {
        tinySpan.addNumbers(tooManyNumbers.begin(), tooManyNumbers.end());
    }
    catch(const std::exception& e)
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    return 0;
}