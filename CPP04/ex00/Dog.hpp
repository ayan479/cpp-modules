/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:25:14 by mayan             #+#    #+#             */
/*   Updated: 2024/05/22 22:34:28 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &object);
		virtual ~Dog();
		Dog &operator=(const Dog &rhs);

		virtual void makeSound() const;
};

#endif
