/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 19:53:40 by mayan             #+#    #+#             */
/*   Updated: 2024/12/25 19:54:59 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm&);
        PresidentialPardonForm(std::string _target);
        ~PresidentialPardonForm();
        
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);

        void execute(Bureaucrat const& executor) const;
};
