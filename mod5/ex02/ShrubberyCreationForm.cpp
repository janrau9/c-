/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:27:42 by jberay            #+#    #+#             */
/*   Updated: 2024/07/04 12:12:32 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubbberyCreationForm() : AForm("Default", 145, 137)
{
    std::cout << "Constructor called" << std::endl;
    file.open(out + ".replace", std::fstream::out | std::fstream::trunc);
    if (file.fail())
    {
        throw ShrubberyCreationForm::fileFailed:what();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    if(file.is_open())
        file.close();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubbberyCreationForm& other)
    : AForm(*other)
{
    std::cout << "copy constructor called" std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        *this = other
    }
    return (*this);
}

const char* ShrubberyCreationForm::fileFailed::what() const noexcept
{
    return ("Failed to create file");
}

ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned() || executor.getGrade() > gradeRequiredToExecute)
        throw Bureaucrat::GradeTooLowException();
this->file <<"              ,@@@@@@@,";
// file <<"      ,,,.   ,@@@@@@/@@,  .oo8888o.";
// file <<"   ,&&&&%&&%,@@@@@/@@@@@@,8888888/8o";
// file <<"   ,%&'\'&&%&&%,@@@@@@@/@@@88888888/88'";
// file <<"   %&&%&%&/%&&%@@@@@/ /@@@88888888888'";
// file <<"   %&&%/ %&@@&&@@@ V /@@' `8888 `/88'";
// file <<"  `&'\' ` /%&'    |.|       '\' '|8'";
// file <<"      |o|        | |         | |";
// file <<"      |.|        | |         | |";
// file <<"jan \\/ ._'/_/__/  ,'_//__\\/.  '_//__/_ ";
    
}