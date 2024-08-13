/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:14:52 by jberay            #+#    #+#             */
/*   Updated: 2024/08/13 11:32:49 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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
    std::cout << "Copy called" << std::endl;        
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "Assignation called" << std::endl;        
    if (this != &other)
    {
        target = other.target;
        AForm::operator=(other);
    }
    return(*this);
}

const char* RobotomyRequestForm::robotomyFailed::what() const noexcept
{
    return ("Robotomy Failed!");
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::cout << "Beep! bop! ";
    srand (time(NULL));
    if (rand() % 2)
        std::cout << target << " has been robotomized!" << std::endl;
    else 
        throw RobotomyRequestForm::robotomyFailed();
}