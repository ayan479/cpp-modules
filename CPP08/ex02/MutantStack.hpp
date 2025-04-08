/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 04:26:32 by mayan             #+#    #+#             */
/*   Updated: 2025/04/08 04:08:59 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        //ocf
        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack &src) : std::stack<T>(src) {}
        ~MutantStack() {}
        MutantStack &operator=(const MutantStack &src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return *this;
        }
        
        //grabbing the iterator from the underlaying container(deque) and renaming it so its easier to use
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        //iterators
        iterator begin() { return std::stack<T>::c.begin(); }// c is the underlying container that actually stores the elements
        iterator end() { return std::stack<T>::c.end(); }

        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }
};