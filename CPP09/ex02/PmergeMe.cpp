/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:00 by mayan             #+#    #+#             */
/*   Updated: 2025/01/17 00:00:00 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
	std::cout << "PmergeMe assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_vectorData = rhs._vectorData;
		_dequeData = rhs._dequeData;
	}
	return *this;
}

bool PmergeMe::isValidNumber(const std::string& str) const
{
	if (str.empty())
		return false;
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	
	std::stringstream ss(str);
	long num;
	ss >> num;
	
	return (num >= 0 && num <= 2147483647);
}

bool PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED << "Error: No input provided" << RESET << std::endl;
		return false;
	}
	
	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (!isValidNumber(arg))
		{
			std::cerr << RED << "Error: Invalid number: " << arg << RESET << std::endl;
			return false;
		}
		
		int num = std::atoi(arg.c_str());
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
	
	// Check for duplicates
	std::vector<int> temp = _vectorData;
	std::sort(temp.begin(), temp.end());
	for (size_t i = 1; i < temp.size(); i++)
	{
		if (temp[i] == temp[i-1])
		{
			std::cerr << RED << "Error: Duplicate number found: " << temp[i] << RESET << std::endl;
			return false;
		}
	}
	
	return true;
}

double PmergeMe::getTimeDifference(struct timeval start, struct timeval end) const
{
	return (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void PmergeMe::printContainer(const std::vector<int>& container, const std::string& label) const
{
	std::cout << label;
	for (size_t i = 0; i < container.size() && i < 5; i++)
	{
		std::cout << container[i] << " ";
	}
	if (container.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

// Vector merge-insertion sort implementation
void PmergeMe::vectorInsertionSort(std::vector<int>& container, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = container[i];
		int j = i - 1;
		while (j >= left && container[j] > key)
		{
			container[j + 1] = container[j];
			j--;
		}
		container[j + 1] = key;
	}
}

void PmergeMe::vectorMerge(std::vector<int>& container, int left, int mid, int right)
{
	std::vector<int> leftArray(container.begin() + left, container.begin() + mid + 1);
	std::vector<int> rightArray(container.begin() + mid + 1, container.begin() + right + 1);
	
	size_t i = 0, j = 0;
	int k = left;
	
	while (i < leftArray.size() && j < rightArray.size())
	{
		if (leftArray[i] <= rightArray[j])
			container[k++] = leftArray[i++];
		else
			container[k++] = rightArray[j++];
	}
	
	while (i < leftArray.size())
		container[k++] = leftArray[i++];
	
	while (j < rightArray.size())
		container[k++] = rightArray[j++];
}

void PmergeMe::vectorMergeSort(std::vector<int>& container, int left, int right)
{
	if (right - left <= 10)
	{
		vectorInsertionSort(container, left, right);
		return;
	}
	
	int mid = left + (right - left) / 2;
	vectorMergeSort(container, left, mid);
	vectorMergeSort(container, mid + 1, right);
	vectorMerge(container, left, mid, right);
}

void PmergeMe::mergeInsertVector(std::vector<int>& container)
{
	if (container.size() <= 1)
		return;
	vectorMergeSort(container, 0, container.size() - 1);
}

// Deque merge-insertion sort implementation
void PmergeMe::dequeInsertionSort(std::deque<int>& container, int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		int key = container[i];
		int j = i - 1;
		while (j >= left && container[j] > key)
		{
			container[j + 1] = container[j];
			j--;
		}
		container[j + 1] = key;
	}
}

void PmergeMe::dequeMerge(std::deque<int>& container, int left, int mid, int right)
{
	std::deque<int> leftArray(container.begin() + left, container.begin() + mid + 1);
	std::deque<int> rightArray(container.begin() + mid + 1, container.begin() + right + 1);
	
	size_t i = 0, j = 0;
	int k = left;
	
	while (i < leftArray.size() && j < rightArray.size())
	{
		if (leftArray[i] <= rightArray[j])
			container[k++] = leftArray[i++];
		else
			container[k++] = rightArray[j++];
	}
	
	while (i < leftArray.size())
		container[k++] = leftArray[i++];
	
	while (j < rightArray.size())
		container[k++] = rightArray[j++];
}

void PmergeMe::dequeMergeSort(std::deque<int>& container, int left, int right)
{
	if (right - left <= 10)
	{
		dequeInsertionSort(container, left, right);
		return;
	}
	
	int mid = left + (right - left) / 2;
	dequeMergeSort(container, left, mid);
	dequeMergeSort(container, mid + 1, right);
	dequeMerge(container, left, mid, right);
}

void PmergeMe::mergeInsertDeque(std::deque<int>& container)
{
	if (container.size() <= 1)
		return;
	dequeMergeSort(container, 0, container.size() - 1);
}

void PmergeMe::sortAndTime()
{
	struct timeval start, end;
	
	// Print before
	printContainer(_vectorData, "Before: ");
	
	// Sort vector
	std::vector<int> vectorCopy = _vectorData;
	gettimeofday(&start, NULL);
	mergeInsertVector(vectorCopy);
	gettimeofday(&end, NULL);
	double vectorTime = getTimeDifference(start, end);
	
	// Sort deque
	std::deque<int> dequeCopy = _dequeData;
	gettimeofday(&start, NULL);
	mergeInsertDeque(dequeCopy);
	gettimeofday(&end, NULL);
	double dequeTime = getTimeDifference(start, end);
	
	// Print after
	std::vector<int> sortedVector(vectorCopy.begin(), vectorCopy.end());
	printContainer(sortedVector, "After:  ");
	
	// Print timing
	std::cout << "Time to process a range of " << _vectorData.size() 
			  << " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size() 
			  << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}
