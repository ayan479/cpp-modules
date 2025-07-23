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

RPN::RPN()
{
	std::cout << "RPN default constructor called" << std::endl;
}

RPN::RPN(const RPN& other) : _stack(other._stack)
{
	std::cout << "RPN copy constructor called" << std::endl;
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}

RPN& RPN::operator=(const RPN& rhs)
{
	std::cout << "RPN assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_stack = rhs._stack;
	}
	return *this;
}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
	if (token.empty())
		return false;
	
	size_t start = 0;
	if (token[0] == '-' || token[0] == '+')
		start = 1;
	
	for (size_t i = start; i < token.length(); i++)
	{
		if (!std::isdigit(token[i]))
			return false;
	}
	return true;
}

double RPN::performOperation(double a, double b, const std::string& op) const
{
	if (op == "+")
		return a + b;
	else if (op == "-")
		return a - b;
	else if (op == "*")
		return a * b;
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Division by zero");
		return a / b;
	}
	throw std::runtime_error("Unknown operator");
}

double RPN::evaluate(const std::string& expression)
{
	std::stringstream ss(expression);
	std::string token;
	
	// Clear the stack for new evaluation
	while (!_stack.empty())
		_stack.pop();
	
	while (ss >> token)
	{
		if (isNumber(token))
		{
			double num = std::atof(token.c_str());
			if (num < 0 || num > 9)
				throw std::runtime_error("Numbers must be single digits (0-9)");
			_stack.push(num);
		}
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Insufficient operands for operation");
			
			double b = _stack.top();
			_stack.pop();
			double a = _stack.top();
			_stack.pop();
			
			double result = performOperation(a, b, token);
			_stack.push(result);
		}
		else
		{
			throw std::runtime_error("Invalid token: " + token);
		}
	}
	
	if (_stack.size() != 1)
		throw std::runtime_error("Invalid expression: wrong number of operands");
	
	return _stack.top();
}
