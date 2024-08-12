/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:14:52 by jberay            #+#    #+#             */
/*   Updated: 2024/08/12 12:25:11 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include RobotomyRequestForm.hpp

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy", 72, 45), target("default")
{
    std::cout << "Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy", 72, 45), target(target)
{
    std::cout << "Parametric constructor called" << std::endl;    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Deconstructor called" << std::endl;        
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), target(other.target)
{
    std::cout << "Deconstructor called" << std::endl;        
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        target = other.target;
        AForm::operator=(other);
        *this = other;
    }
    return(*this);
}

const char* RobotomyRequestForm::robotomyFailedFailed::what() const noexcept
{
    return ("Failed to create file");
}
