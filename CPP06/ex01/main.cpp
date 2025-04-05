/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 01:31:14 by mayan             #+#    #+#             */
/*   Updated: 2025/03/24 23:43:37 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    data.name = "John";
    data.age = 42;

    //b4 serialization
    std::cout << "Name: " << data.name << std::endl;
    std::cout << "Age: " << data.age << std::endl;
    std::cout << "ptr address: " << &data << std::endl;
    // Serialize the data
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "Serialized: " << serialized << std::endl;
    
    // Deserialize the data
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << GREEN <<"Deserialized: " << deserialized << std::endl;
    std::cout << "Name: " << deserialized->name << std::endl;
    std::cout << "Age: " << deserialized->age << RESET <<std::endl;
    
    return 0;
}