/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:23:08 by mayan             #+#    #+#             */
/*   Updated: 2025/03/25 23:19:30 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib> //rand
#include <ctime> //time

class Base
{
    public:
        virtual ~Base() {};
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

