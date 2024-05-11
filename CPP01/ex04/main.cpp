/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:27:54 by mayan             #+#    #+#             */
/*   Updated: 2024/05/11 20:39:24 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void ft_replace(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::ifstream inputFile(filename.c_str(), std::ios::in);
	if (!inputFile.is_open())
	{
		std::cout << "Error: could not open file" << std::endl;
		return ;
	}

	std::ofstream outputFile((filename + ".replace").c_str(), std::ios::out);
	if (!outputFile.is_open())
	{
		std::cout << "Error: could not create file" << std::endl;
		inputFile.close();
		return ;
	}

	std::string line;
	while (std::getline(inputFile, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos += s2.length();
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
}

int main(int ac, char **av)
{
		if (ac != 4)
		{
			std::cout << "Error: wrong number of arguments" << std::endl;
			std::cout << "Usage: ./replace filename s1 s2" << std::endl;
			return (1);
		}
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];

		if (s1.empty() || s2.empty())
		{
			std::cout << "Error: s1 or s2 is empty" << std::endl;
			return (1);
		}
		ft_replace(filename, s1, s2);
		return (0);
}



/** File streams
Streams that interact with files. There are three types of stream objects for working with files: ifstream, ofstream, and fstream

These classes have istream, ostream, and iostream as base classes, respectively
-An istream object represents a file input stream so you can only read it
-An ofstream object represents a file output stream that you can only write to it
-An fstream is a file stream that you can read or write

You can associate a file stream object with a physical file when you create it.
You can also create a file stream object that isn't assciated with a file, and then c-all a
function member to establish the connection with a specific file

In order to read or write a file, you must "open" the file; this attaches the file to your program
via the operating system with a set of permissions that determine what you can do with it.
If you create a file stream object with an initial association to a file, the file is opened and available for use immediately

A file stream has some important properties. It has a length, which corresponds to the number of characters in the stream;
it has a beginning, which is index position of the first character in the stream; and it has an end,
which is the index position one beyond the last character in the stream.
It also has a current position, which is the index position of the character in the stream
where the next read or write operation will start. The first character in a file stream is at index position 0.
These properties provide a way for you to move around a file to read the particular
parts that you’re interested in or to overwrite selected areas of the file. */

