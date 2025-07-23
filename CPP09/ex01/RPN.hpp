/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:00 by mayan             #+#    #+#             */
/*   Updated: 2025/01/17 00:00:00 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

class RPN
{
	private:
		std::stack<double> _stack;
		bool	isOperator(const std::string& token) const;
		bool	isNumber(const std::string& token) const;
		double	performOperation(double a, double b, const std::string& op) const;

	public:
		RPN();
		RPN(const RPN& other);
		~RPN();
		RPN& operator=(const RPN& rhs);

		double	evaluate(const std::string& expression);
};

#endif
