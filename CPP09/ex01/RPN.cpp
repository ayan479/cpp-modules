/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:00 by mayan             #+#    #+#             */
/*   Updated: 2025/01/17 00:00:00 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other) 
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

void RPN::performOperation(char op) 
{
    if (_stack.size() < 2)
        throw std::runtime_error("Insufficient operands");
        
    int b = _stack.top(); _stack.pop();//read top of stack, then remove it
    int a = _stack.top(); _stack.pop();
	
    switch (op) 
	{
		case '+':
				_stack.push(a + b);
				break;
		case '-':
				_stack.push(a - b);
				break;
		case '*':
				_stack.push(a * b);
				break;
		case '/':
				if (b == 0)//zero div check
					throw std::runtime_error("Division by zero");
				_stack.push(a / b);
				break;
		default:
			throw std::runtime_error("Invalid operator");
	}
}

void RPN::calculate(const std::string &expression) {
    try
	{
        for (size_t i = 0; i < expression.length(); i++)
		{
            char c = expression[i];
            
            if (c == ' ')// Skip whitespace
                continue;
                
            if (c >= '0' && c <= '9') // If it's a digit
			{
                _stack.push(c - '0');// Convert char to int
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/') // If it's an operator
			{
                performOperation(c);
            }
            else
			{
                throw std::runtime_error("Invalid character");
            }
        }
        
        if (_stack.size() != 1)
            throw std::runtime_error("Invalid expression");
            
        std::cout << _stack.top() << std::endl;// Print the result, shuld only be one element left in the stack
    }
    catch (std::exception &e) 
	{
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}
