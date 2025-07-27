/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:00 by mayan             #+#    #+#             */
/*   Updated: 2025/01/17 00:00:00 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>
#include <cstdlib>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;
		
		// Ford-Johnson algo for vector
		void fordJohnsonVector(std::vector<int>& container);
		void insertionSortVector(std::vector<int>& container, int left, int right);
		
		// Ford-Johnson algo for deque  
		void fordJohnsonDeque(std::deque<int>& container);
		void insertionSortDeque(std::deque<int>& container, int left, int right);

	public:
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& rhs);

		void sort();
};

#endif
