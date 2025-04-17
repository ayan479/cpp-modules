/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:57:19 by mayan             #+#    #+#             */
/*   Updated: 2025/04/13 13:51:09 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i)
        vec.push_back(i); // push_back() adds an element to the end of the vector
        
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 15); // not in the vector
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 0);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::vector<int>::iterator it = easyfind(vec, -500); // not in the vector
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    for (int i = 0; i < 10; ++i)
        lst.push_back(i); // push_back() adds an element to the end of the list
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    try
    {
        std::list<int>::iterator it = easyfind(lst, 5);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << std::endl;
    }
}