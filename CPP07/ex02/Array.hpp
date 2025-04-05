/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:18:27 by mayan             #+#    #+#             */
/*   Updated: 2025/04/01 02:25:29 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stdexcept> 
#include <iostream>
#include <string>
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"

template <typename T>
class Array
{
    private:
        T* _elmnt;
        unsigned int _size;
    public:
        Array() : _elmnt(NULL), _size(0) {}
        Array(unsigned int n) : _elmnt(new T[n]()), _size(n) {}// create array with n elements
        ~Array()
        {
            if (_elmnt)
                delete[] _elmnt;
        }
        
        Array(const Array& other) : _elmnt(NULL), _size(0)
        {
            *this = other;
        }
        
        Array& operator=(const Array& rhs) // we want deep copy
        {
            if (this != &rhs)
            {
                if (_elmnt)
                    delete[] _elmnt; //clean up old memory
                    
                _size = rhs._size;
                if (_size) // > 0
                {
                    _elmnt = new T[_size];
                    for (unsigned int i = 0; i < _size; i++)
                        _elmnt[i] = rhs._elmnt[i];
                }
                else
                    _elmnt = NULL;    
            }
            return *this;
        }

        T& operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _elmnt[index];
        }

        const T& operator[](unsigned int index) const //for const objects
        {
            if (index >= _size)
                throw std::out_of_range("Index out of range");
            return _elmnt[index];
        }
        
        unsigned int size() const
        {
            return _size;
        }
};
