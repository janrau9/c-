/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:55:55 by jberay            #+#    #+#             */
/*   Updated: 2024/08/13 12:24:35 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{	
		std::cout << "####################" << std::endl;
		std::cout << "Creating Bureaucrats" << std::endl;
		
		Bureaucrat jan("jan", 1);
		std::cout << jan << std::endl;
		Bureaucrat rau("rau", 150);
		std::cout << rau << std::endl;


		std::cout << "####################" << std::endl;
		std::cout << "Creating intern" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << "form rrf: " << *rrf << std::endl;
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "jose");
		std::cout << "form rrf: " << *rrf << std::endl;
		if (rrf)
		{
			std::cout << "####################" << std::endl;
			std::cout << "Signing form" << std::endl;
			jan.signForm(*rrf);
			rau.signForm(*rrf);
			
			std::cout << "####################" << std::endl;
			std::cout << "Executing form" << std::endl;
			jan.executeForm(*rrf);
			rau.executeForm(*rrf);
			delete rrf;
		}
		
		rrf = someRandomIntern.makeForm("unknown", "jose");
		
}