/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:50:34 by jberay            #+#    #+#             */
/*   Updated: 2024/08/13 11:32:43 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential form", 25, 5), target("default")
{
    std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential form", 25, 5), target(target)
{
    std::cout << "Parametric constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "Copy called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "Assignation called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}