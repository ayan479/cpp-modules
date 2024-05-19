/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:27:03 by mayan             #+#    #+#             */
/*   Updated: 2024/05/19 20:34:18 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
  public:
	FragTrap();
	FragTrap(const FragTrap &object);
	~FragTrap();
	FragTrap &operator=(const FragTrap &rhs);

	FragTrap(std::string name);
	void attack(std::string const &target);
	void highFivesGuys(void);
};

#endif
