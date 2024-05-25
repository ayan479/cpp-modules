/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 22:52:32 by mayan             #+#    #+#             */
/*   Updated: 2024/05/24 22:54:25 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << BLUE <<"-                           Construction                                  -"<< RESET << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const Animal* i = new Cat();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const Animal* j = new Dog();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	std::cout << BLUE <<"-                              getType()                                    -"<< RESET << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << BLUE <<"-                              makeSound()                                  -"<< RESET << std::endl;
	i->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	j->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << RED << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << "|                             WRONG-ANIMAL                                  |" << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << BLUE <<"-                           Construction                                    -"<< RESET << std::endl;
	std::cout << RED << std::endl;
	const WrongCat* i1 = new WrongCat();
	std::cout << RED <<"-----------------------------------------------------------------------------"<< std::endl;
	const WrongAnimal* j1 = new WrongCat();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const WrongAnimal* meta1 = new WrongAnimal();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << BLUE <<"-                              getType()                                    -"<< std::endl;
	std::cout << RED << std::endl;
	std::cout << i1->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << j1->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << meta1->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << BLUE <<"-                              makeSound()                                  -"<< RESET << std::endl;
	std::cout << RED << std::endl;
	i1->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	j1->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	meta1->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << RESET << std::endl;
	delete meta;
	delete meta1;
	delete i;
	delete i1;
	delete j;
	delete j1;
	return 0;
}

// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();

// return 0;
// }
