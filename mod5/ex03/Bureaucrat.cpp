/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:50:31 by jberay            #+#    #+#             */
/*   Updated: 2024/08/12 11:44:29 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("name"), grade(150)
{
    std::cout << "default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    std::cout << "Parametric constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
    std::cout << "copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "assignation called" << std::endl;
    if(this != &other)
    {
        grade = other.grade;
    }
    return(*this);
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return ("Grade too low!");
}

std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl; 
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
       std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& B)
{
    os << B.getName() << ", bureaucrat grade " << B.getGrade() << std::endl;
    return os;
}