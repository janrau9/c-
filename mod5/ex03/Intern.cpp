/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:49:52 by jberay            #+#    #+#             */
/*   Updated: 2024/08/13 12:11:17 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "constructor called" << std::endl;   
}

Intern::Intern(const Intern& other)
{
    std::cout << "copy constructor called" << std::endl;   
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    std::cout << "Assignation called" << std::endl;
    (void)other;
    return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i = 0;
	while (i < 3)
	{
		if (!formName.compare(forms[i]))
			break;
		i++;
	}
	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(formTarget));
		case 1:
			return (new RobotomyRequestForm(formTarget));
		case 2:
			return (new PresidentialPardonForm(formTarget));
		default:
			std::cout << "Not valid!" << std::endl;
			return (NULL);
	}
}