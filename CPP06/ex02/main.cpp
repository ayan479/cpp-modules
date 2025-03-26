/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 23:04:24 by mayan             #+#    #+#             */
/*   Updated: 2025/03/26 18:29:54 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    //randomly generate a derived class instance
    //and assign it to a base class pointer
    Base *base = generate();
    Base *base2 = generate();
    Base *base3 = generate();
    //identify the derived class instance
    //using the base class pointer via dynamic_cast
    identify(base);
    identify(*base);
    identify(base2);
    identify(*base2);
    identify(base3);
    identify(*base3);
    delete base2;
    delete base3;
    delete base;
    return 0;
}
