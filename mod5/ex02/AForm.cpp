/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:18:33 by jberay            #+#    #+#             */
/*   Updated: 2024/11/18 10:24:39 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("name"), isSigned(false), gradeRequiredToSign(150), gradeRequiredToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute)
{
    std::cout << "Parametric constructor called" << std::endl;
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned),
      gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Assignation called" << std::endl;
    if (this != &other)
    {
        isSigned = other.isSigned;
    }
    return (*this);
}

const char *AForm::GradeTooHighException::what() const noexcept
{
    return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const noexcept
{
    return ("Grade too low!");
}

std::string AForm::getName() const
{
    return (name);
}

bool AForm::getIsSigned() const
{
    return (isSigned);
}

int AForm::getGradeRequiredToSign() const
{
    return (gradeRequiredToSign);
}

int AForm::getGradeRequiredToExecute() const
{
    return (gradeRequiredToExecute);
}

void AForm::beSigned(const Bureaucrat &B)
{
    if (isSigned)
        throw std::logic_error("Form already signed");
    if (B.getGrade() <= gradeRequiredToSign)
        isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw std::runtime_error("Form is not signed!");
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw Bureaucrat::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &F)
{
    os << "Name: " << F.getName() << std::endl
       << "is AForm signed: " << F.getIsSigned() << std::endl
       << "Grade required to sign it: " << F.getGradeRequiredToSign() << std::endl
       << "Grade required to execute it: " << F.getGradeRequiredToExecute() << std::endl;
    return os;
}