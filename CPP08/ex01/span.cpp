/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 02:09:12 by mayan             #+#    #+#             */
/*   Updated: 2025/04/07 04:09:28 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(unsigned int n) : _max(n)
{
}

Span::Span(const Span &src) : _max(src._max), _numbers(src._numbers)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        _max = src._max;
        _numbers = src._numbers;
    }
    return *this;
}

void Span::addNumber(int n)
{
    if (_numbers.size() >= _max)
        throw SpanFullException();
    _numbers.push_back(n);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw SpanNotEnoughException();
    
    //sort numbers
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    
    //find the shortest span
    int shortest = sorted[1] - sorted[0]; // initialize with the first span
    for (size_t i = 1; i < sorted.size() - 1; ++i)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < shortest)
            shortest = span;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw SpanNotEnoughException();
    
    //find the longest span
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (std::distance(begin, end) + _numbers.size() > _max) // check if adding the numbers will exceed the max size
        throw SpanFullException();
    _numbers.insert(_numbers.end(), begin, end); // add the numbers to the vector
}


        
