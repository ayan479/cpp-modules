/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:31:29 by mayan             #+#    #+#             */
/*   Updated: 2025/03/24 23:43:50 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

#define GREEN "\033[32m"
#define RESET "\033[0m"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer&);
        ~Serializer();
        Serializer& operator=(const Serializer&);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};
