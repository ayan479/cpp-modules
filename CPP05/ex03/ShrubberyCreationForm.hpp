/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:06:02 by mayan             #+#    #+#             */
/*   Updated: 2024/12/24 20:04:01 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "AForm.hpp"
#include <fstream> // std::ofstream 

 class ShrubberyCreationForm : public AForm
 {
    private:
        std::string _target;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm(std::string _target);
        ~ShrubberyCreationForm();
        
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);

        void execute(Bureaucrat const& executor) const;
 };
 