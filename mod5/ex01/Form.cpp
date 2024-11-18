/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:33 by jberay            #+#    #+#             */
/*   Updated: 2024/11/18 10:16:37 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("name"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute)
{
    std::cout << "Parametric constructor called" << std::endl;
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned),
      gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

const char *Form::GradeTooHighException::what() const noexcept
{
    return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return ("Grade too low!");
}

std::string Form::getName() const
{
    return (name);
}

bool Form::getIsSigned() const
{
    return (isSigned);
}

int Form::getGradeRequiredToSign() const
{
    return (gradeRequiredToSign);
}

int Form::getGradeRequiredToExecute() const
{
    return (gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat &B)
{
    if (isSigned) 
        throw std::logic_error("Form already signed");
    if (B.getGrade() <= gradeRequiredToSign)
        isSigned = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &F)
{
    os << "Name: " << F.getName() << std::endl
       << "is Form signed: " << F.getIsSigned() << std::endl
       << "Grade required to sign it: " << F.getGradeRequiredToSign() << std::endl
       << "Grade required to execute it: " << F.getGradeRequiredToExecute() << std::endl;
    return os;
}