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
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <sstream>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

class PmergeMe
{
	private:
		std::vector<int>	_vectorData;
		std::deque<int>		_dequeData;

		// Vector implementation
		void				mergeInsertVector(std::vector<int>& container);
		void				vectorMergeSort(std::vector<int>& container, int left, int right);
		void				vectorMerge(std::vector<int>& container, int left, int mid, int right);
		void				vectorInsertionSort(std::vector<int>& container, int left, int right);

		// Deque implementation
		void				mergeInsertDeque(std::deque<int>& container);
		void				dequeMergeSort(std::deque<int>& container, int left, int right);
		void				dequeMerge(std::deque<int>& container, int left, int mid, int right);
		void				dequeInsertionSort(std::deque<int>& container, int left, int right);

		// Utility functions
		bool				isValidNumber(const std::string& str) const;
		double				getTimeDifference(struct timeval start, struct timeval end) const;
		void				printContainer(const std::vector<int>& container, const std::string& label) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& rhs);

		bool				parseInput(int argc, char **argv);
		void				sortAndTime();
};

#endif
