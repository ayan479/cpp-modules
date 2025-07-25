/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 00:00:00 by mayan             #+#    #+#             */
/*   Updated: 2025/07/26 17:50:32 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream dbFile("data.csv");
	if (!dbFile.is_open())
		throw std::runtime_error("Error: could not open database file");
	
	std::string line;
	std::getline(dbFile, line); // Skip header line
	
	while (std::getline(dbFile, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue;
		
		std::string date = line.substr(0, pos);
		std::string rateStr = line.substr(pos + 1);
		
		trimWhitespace(date);
		trimWhitespace(rateStr);
		std::stringstream rateStream(rateStr);
		double rate;
		if (rateStream >> rate)// extract from stream into rate
			_exchangeRates[date] = rate;//assign to map
	}
	dbFile.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this != &rhs)
		_exchangeRates = rhs._exchangeRates;
	return *this;
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year, month, day;
	std::stringstream ss(date);
	char dash;
	ss >> year >> dash >> month >> dash >> day; // >> is type aware, it knows wat goes where

	if (ss.fail() || !ss.eof())//non-numeric or xtra
		return false;

	if (month < 1 || month > 12 || day < 1 || day > 31)// within range
		return false;

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) //april, june, september, november
		return false;

	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
			return day <= 29; // Leap year
		else
			return day <= 28; // Non-leap year
	}

	return true;
}

void BitcoinExchange::trimWhitespace(std::string& str) const
{
	while (!str.empty() && std::isspace(str[0]))
		str.erase(0, 1);
	while (!str.empty() && std::isspace(str[str.length() - 1]))
		str.erase(str.length() - 1);
}

void BitcoinExchange::processExchange(const std::string& filename)
{
	//Process input file
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << RED << "Error: could not open file." << RESET << std::endl;
		return;
	}
	
	std::string line;
	std::getline(inputFile, line); // Skip header line
	
	while (std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
			
		size_t pos = line.find(" | ");
		if (pos == std::string::npos)
		{
			std::cerr << RED << "Error: bad input => " << line << RESET << std::endl;
			continue;
		}
		
		std::string date = line.substr(0, pos);
		std::string valueStr = line.substr(pos + 3);
		
		trimWhitespace(date);
		trimWhitespace(valueStr);
		
		if (!isValidDate(date))
		{
			std::cerr << RED << "Error: bad input => " << date << RESET << std::endl;
			continue;
		}
		
		// Value validation
		double value;
		std::stringstream ss(valueStr);
		if (!(ss >> value) || !ss.eof())
		{
			std::cerr << RED << "Error: bad input => " << valueStr << RESET << std::endl;
			continue;
		}
		
		if (value < 0 || value > 1000)
		{
			std::cerr << RED << "Error: bad input => " << valueStr <<" Not between 0 and 1000" <<RESET << std::endl;
			continue;
		}
		
		// Find exchange rate
		std::map<std::string, double>::const_iterator it = _exchangeRates.upper_bound(date);// find the first date that is greater than the given date
		if (it == _exchangeRates.begin())//date is too early
		{
			std::cerr << RED << "Error: no exchange rate data available for " << date << RESET << std::endl;
			continue;
		}
		--it; // get rate from period that our date falls into
		double rate = it->second; // Get the rate from the map (second cuz maps are pairs, first is key)
		
		std::cout << GREEN << date << " => " << value << " = " << std::fixed << std::setprecision(2) << (value * rate) << RESET << std::endl;
	}
	
	inputFile.close();
}
