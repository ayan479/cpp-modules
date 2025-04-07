/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 19:26:05 by mayan             #+#    #+#             */
/*   Updated: 2025/04/07 04:11:30 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <limits>   
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class Span
{
    private:
        unsigned int _max; // max size of the vector
        std::vector<int> _numbers; // vector to store the numbers
    public:
        Span(unsigned int n);
        Span(const Span &src);
        ~Span();
        Span &operator=(const Span &src);

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        
        class SpanFullException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Span is full";
                }
        };

        class SpanNotEnoughException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Not enough numbers in the span. Need at least 2 numbers.";
                }
        };
};

