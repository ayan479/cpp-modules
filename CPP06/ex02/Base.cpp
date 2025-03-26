/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:41:43 by mayan             #+#    #+#             */
/*   Updated: 2025/03/25 23:23:51 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(NULL));
        seeded = true;
    }
    int i = rand() % 3;

    switch (i)
    {
        case 0:
            std::cout << "A instance created" << std::endl;
            return new A;
        case 1:
            std::cout << "B instance created" << std::endl;
            return new B;
        case 2:
            std::cout << "C instance created" << std::endl;
            return new C;
        default:
            return NULL;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

// References in C++ can never be null (unlike pointers)
// When a reference cast fails, a std::bad_cast exception is thrown
// The only way to detect failure is to catch this exception
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch (...) {}
    std::cout << "Unknown" << std::endl;
}
    
        