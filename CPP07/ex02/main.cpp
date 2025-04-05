/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:17:24 by mayan             #+#    #+#             */
/*   Updated: 2025/04/01 03:25:55 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    std::cout << BLUE << "===== Testing Empty Array =====" << RESET << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    // Should throw exception when accessing empty array
    std::cout << YELLOW << "Trying to access element in empty array:" << RESET << std::endl;
    try 
    {
        std::cout << empty[0] << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    std::cout << BLUE << "\n===== Testing Integer Array =====" << RESET << std::endl;
    // Creating and filling array
    Array<int> numbers(5);
    for (unsigned int i = 0; i < numbers.size(); i++)
        numbers[i] = i * 10;
    
    std::cout << "Array contents:" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    
    std::cout << YELLOW << "Trying to access out-of-bounds element:" << RESET << std::endl;
    try 
    {
        std::cout << numbers[10] << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << RED << "Exception: " << e.what() << RESET << std::endl;
    }
    
    std::cout << BLUE << "\n===== Testing Copy Constructor =====" << RESET << std::endl;
    Array<int> copy(numbers);
    std::cout << "Original array:" << std::endl;
    for (unsigned int i = 0; i < numbers.size(); i++)
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    
    std::cout << "Copied array:" << std::endl;
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << "copy[" << i << "] = " << copy[i] << std::endl;
    
    std::cout << YELLOW << "Modifying copied array:" << RESET << std::endl;
    copy[2] = 999;
    std::cout << "After modification:" << std::endl;
    std::cout << "Original numbers[2] = " << numbers[2] << std::endl;
    std::cout << "Modified copy[2] = " << copy[2] << std::endl;
    
    std::cout << BLUE << "\n===== Testing Assignment Operator =====" << RESET << std::endl;
    Array<int> assigned;
    assigned = numbers;
    std::cout << "After assignment:" << std::endl;
    std::cout << "assigned.size() = " << assigned.size() << std::endl;
    for (unsigned int i = 0; i < assigned.size(); i++)
        std::cout << "assigned[" << i << "] = " << assigned[i] << std::endl;
    
    std::cout << BLUE << "\n===== Testing With Strings =====" << RESET << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "42";
    strings[2] = "World";
    
    std::cout << "String array:" << std::endl;
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
    
    std::cout << BLUE << "\n===== Testing With Const Array =====" << RESET << std::endl;
    const Array<int> constArray = numbers;
    std::cout << "Const array size: " << constArray.size() << std::endl;
    std::cout << "Reading from const array: constArray[1] = " << constArray[1] << std::endl;
    
    // constArray[1] = 42;  // Error: assignment of read-only location
    return 0;
}