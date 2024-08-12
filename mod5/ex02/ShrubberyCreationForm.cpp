/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:27:42 by jberay            #+#    #+#             */
/*   Updated: 2024/08/12 12:01:41 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("default")
{
    std::cout << "Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 145, 137), target(target)
{
    std::cout << "parametric constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
{
    std::cout << "copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        *this = other;
    }
    return (*this);
}

const char* ShrubberyCreationForm::fileFailed::what() const noexcept
{
    return ("Failed to create file");
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);
    std::ofstream file;
    file.open(target + "_shrubbery", std::fstream::out);
    if (file.fail())
    {
        throw ShrubberyCreationForm::fileFailed();
    }

    file <<"              ,@@@@@@@," << std::endl;
    file <<"      ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    file <<"   ,&&&&%&&%,@@@@@/@@@@@@,8888888/8o" << std::endl;
    file <<"   ,%&'\'&&%&&%,@@@@@@@/@@@88888888/88'" << std::endl;
    file <<"   %&&%&%&/%&&%@@@@@/ /@@@88888888888'" << std::endl;
    file <<"   %&&%/ %&@@&&@@@ V /@@' `8888 `/88'" << std::endl;
    file <<"  `&'\' ` /%&'    |.|       '\' '|8'" << std::endl;
    file <<"      |o|        | |         | |" << std::endl;
    file <<"      |.|        | |         | |" << std::endl;
    file <<"jan \\/ ._'/_/__/  ,'_//__\\/.  '_//__/_ " << std::endl;
    
}