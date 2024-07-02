/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:33 by jberay            #+#    #+#             */
/*   Updated: 2024/07/02 12:27:25 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("name"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
    std::cout << "Parametric constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned), \
    gradeRequiredToSign(other.getGradeRequiredToSign), gradeRequiredToExecute(other.getGradeRequiredToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if(this != &other)
    {
        name = other.name;
        isSigned = other.isSigned;
        gradeRequiredToSign = other.gradeRequiredToSign;
        gradeRequiredToExecute = other.gradeRequiredToExecute;
    }
    return (*this);
}

Form::GradeTooHighException::what() const noexcept
{
    
}