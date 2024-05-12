/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:39:50 by mayan             #+#    #+#             */
/*   Updated: 2024/05/12 02:39:50 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce();
		void setName(std::string name);
};
Zombie* zombieHorde(int N, std::string name);

#endif
