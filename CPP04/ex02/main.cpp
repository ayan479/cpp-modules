/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:52:32 by mayan             #+#    #+#             */
/*   Updated: 2024/05/25 18:26:37 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal test;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	std::cout << std::endl;

	Animal* animal[6];

	for (int i = 0; i < 6; i++)
	{
		if (i >= 3)
			animal[i] = new Cat();
		else
			animal[i] = new Dog();
	}

	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 6; i++)
	{
		animal[i]->getType();
		animal[i]->makeSound();
	}
	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 6; i++)
	{
		delete animal[i];
	}
	std::cout << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}
	return 0;
}