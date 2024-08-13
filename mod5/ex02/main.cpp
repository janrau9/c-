/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:55:55 by jberay            #+#    #+#             */
/*   Updated: 2024/08/13 11:38:37 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main()
{	
	try
	{
		std::cout << "####################" << std::endl;
		std::cout << "Creating Bureaucrats" << std::endl;
		
		Bureaucrat jan("jan", 1);
		std::cout << jan << std::endl;
		Bureaucrat rau("rau", 150);
		std::cout << rau << std::endl;

		std::cout << "####################" << std::endl;
		std::cout << "Creating Forms, copy and assignation" << std::endl;

		ShrubberyCreationForm Sform("home");
		ShrubberyCreationForm Scp(Sform);
		ShrubberyCreationForm Sassig = Sform;
		std::cout << "S form : " << Sform << std::endl;
		std::cout << "S copy : " << Scp << std::endl;
		std::cout << "S assignation : " << Sassig << std::endl;
		
		RobotomyRequestForm Rform("dog");
		RobotomyRequestForm Rcp(Rform);
		RobotomyRequestForm Rassig = Rform;
		std::cout << "R form : " << Rform << std::endl;
		std::cout << "R copy : " << Rcp << std::endl;
		std::cout << "R assignation : " << Rassig << std::endl;

		PresidentialPardonForm Pform("jose");
		PresidentialPardonForm Pcp(Pform);
		PresidentialPardonForm Passig(Pform);
		std::cout << "P form : " << Pform << std::endl;
		std::cout << "P copy : " << Pform << std::endl;
		std::cout << "P assignation : " << Pform << std::endl;
		try
		{
			std::cout << "####################" << std::endl;
			std::cout << "Signing forms" << std::endl;
			jan.signForm(Sform);
			rau.signForm(Sform);
			
			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Rform);
			rau.signForm(Rform);

			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Pform);
			rau.signForm(Pform);
			
			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Scp);
			rau.signForm(Scp);
			
			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Rcp);
			rau.signForm(Rcp);

			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Pcp);
			rau.signForm(Pcp);

			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Sassig);
			rau.signForm(Sassig);

			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Rassig);
			rau.signForm(Rassig);

			std::cout << "####################" << std::endl << std::endl;
			jan.signForm(Passig);
			rau.signForm(Passig);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			std::cout << "####################" << std::endl;
			std::cout << "executing forms" << std::endl;
			jan.executeForm(Sform);
			rau.executeForm(Sform);

			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Rform);
			rau.executeForm(Rform);

			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Pform);
			rau.executeForm(Pform);
			
			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Scp);
			rau.executeForm(Scp);

			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Rcp);
			rau.executeForm(Rcp);

			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Pcp);
			rau.executeForm(Pcp);

			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Sassig);
			rau.executeForm(Sassig);
			
			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Rassig);
			rau.executeForm(Rassig);
			
			std::cout << "####################" << std::endl << std::endl;
			jan.executeForm(Passig);
			rau.executeForm(Passig);
			
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}