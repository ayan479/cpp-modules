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

PmergeMe::PmergeMe(int argc, char **argv) 
{
    if (argc < 2)
        throw std::runtime_error("Error");

    for (int i = 1; i < argc; i++) {
        char *end;
        long num = std::strtol(argv[i], &end, 10);
        
        if (*end != '\0' || num <= 0 || num > 2147483647)
            throw std::runtime_error("Error");
        
        _vector.push_back(static_cast<int>(num));
        _deque.push_back(static_cast<int>(num));
    }
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs) {
        _vector = rhs._vector;
        _deque = rhs._deque;
    }
    return *this;
}

bool PmergeMe::parseInput(int argc, char **argv)
{
    if (argc < 2) 
	{
        std::cerr << RED << "Error" << RESET << std::endl;
        return false;
    }

    for (int i = 1; i < argc; i++)
	{
        char *end;
        long num = std::strtol(argv[i], &end, 10);
        
        if (*end != '\0' || num <= 0 || num > 2147483647) 
		{
            std::cerr << RED << "Error" << RESET << std::endl;
            return false;
        }
        
        _vector.push_back(static_cast<int>(num));
        _deque.push_back(static_cast<int>(num));
    }
    
    return true;
}

void PmergeMe::insertionSortVector(std::vector<int>& container, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = container[i];
        int j = i - 1;
        while (j >= left && container[j] > key) {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

void PmergeMe::fordJohnsonVector(std::vector<int>& container) {
    if (container.size() <= 1) return;
    
    // For small arrays, use insertion sort
    if (container.size() <= 20) {
        insertionSortVector(container, 0, container.size() - 1);
        return;
    }
    
    // Step 1: Group elements into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = container.size() % 2 == 1;
    int oddElement = hasOdd ? container.back() : 0;
    
    for (size_t i = 0; i < container.size() - (hasOdd ? 1 : 0); i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    // Step 2: Sort pairs by their larger element (recursive)
    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); i++) {
        larger.push_back(pairs[i].second);
    }
    fordJohnsonVector(larger);
    
    // Step 3: Create main chain with larger elements
    std::vector<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < larger.size(); i++) {
        mainChain.push_back(larger[i]);
        // Find corresponding smaller element
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == larger[i]) {
                pending.push_back(pairs[j].first);
                break;
            }
        }
    }
    
    // Step 4: Insert pending elements using binary insertion
    for (size_t i = 0; i < pending.size(); i++) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }
    
    // Step 5: Insert odd element if exists
    if (hasOdd) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }
    
    container = mainChain;
}

void PmergeMe::insertionSortDeque(std::deque<int>& container, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = container[i];
        int j = i - 1;
        while (j >= left && container[j] > key) {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key;
    }
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& container) {
    if (container.size() <= 1) return;
    
    // For small arrays, use insertion sort
    if (container.size() <= 20) {
        insertionSortDeque(container, 0, container.size() - 1);
        return;
    }
    
    // Step 1: Group elements into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = container.size() % 2 == 1;
    int oddElement = hasOdd ? container.back() : 0;
    
    for (size_t i = 0; i < container.size() - (hasOdd ? 1 : 0); i += 2) {
        int a = container[i];
        int b = container[i + 1];
        if (a > b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    
    // Step 2: Sort pairs by their larger element (recursive)
    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); i++) {
        larger.push_back(pairs[i].second);
    }
    fordJohnsonDeque(larger);
    
    // Step 3: Create main chain with larger elements
    std::deque<int> mainChain;
    std::vector<int> pending;
    
    for (size_t i = 0; i < larger.size(); i++) {
        mainChain.push_back(larger[i]);
        // Find corresponding smaller element
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].second == larger[i]) {
                pending.push_back(pairs[j].first);
                break;
            }
        }
    }
    
    // Step 4: Insert pending elements using binary insertion
    for (size_t i = 0; i < pending.size(); i++) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }
    
    // Step 5: Insert odd element if exists
    if (hasOdd) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(pos, oddElement);
    }
    
    container = mainChain;
}

void PmergeMe::sort() {
    // Print before
    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i];
        if (i < _vector.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    // Time vector sort
    struct timeval start, end;
    gettimeofday(&start, NULL);
    fordJohnsonVector(_vector);
    gettimeofday(&end, NULL);
    double vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    // Time deque sort
    gettimeofday(&start, NULL);
    fordJohnsonDeque(_deque);
    gettimeofday(&end, NULL);
    double dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
    
    // Print after
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++) {
        std::cout << _vector[i];
        if (i < _vector.size() - 1) std::cout << " ";
    }
    std::cout << std::endl;
    
    // Print timing
    std::cout << "Time to process a range of " << _vector.size() 
              << " elements with std::vector : " << vectorTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() 
              << " elements with std::deque  : " << dequeTime << " us" << std::endl;
}
