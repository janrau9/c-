/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:55:55 by jberay            #+#    #+#             */
/*   Updated: 2024/11/18 10:38:08 by jberay           ###   ########.fr       */
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
			std::cout << std::endl << "##Signing forms original##" << std::endl ;
			jan.signForm(Sform);
			rau.signForm(Sform);
			
			jan.signForm(Rform);
			rau.signForm(Rform);

			jan.signForm(Pform);
			rau.signForm(Pform);
			
			std::cout << std::endl <<"##Signing forms copy##" << std::endl ;
			rau.signForm(Scp);
			jan.signForm(Scp);
			
			rau.signForm(Rcp);
			jan.signForm(Rcp);

			rau.signForm(Pcp);
			jan.signForm(Pcp);

			std::cout << std::endl <<"##Signing forms assignation##"  << std::endl;
			jan.signForm(Sassig);
			rau.signForm(Sassig);

			jan.signForm(Rassig);
			rau.signForm(Rassig);

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
			std::cout << std::endl << "##executing forms original##" << std::endl ;
			jan.executeForm(Sform);
			rau.executeForm(Sform);

			jan.executeForm(Rform);
			rau.executeForm(Rform);

			jan.executeForm(Pform);
			rau.executeForm(Pform);
			
			std::cout << std::endl << "##executing forms copy##" << std::endl ;
			jan.executeForm(Scp);
			rau.executeForm(Scp);

			jan.executeForm(Rcp);
			rau.executeForm(Rcp);

			jan.executeForm(Pcp);
			rau.executeForm(Pcp);

			std::cout << std::endl << "##executing forms assignation##" << std::endl ;
			jan.executeForm(Sassig);
			rau.executeForm(Sassig);
			
			jan.executeForm(Rassig);
			rau.executeForm(Rassig);
			
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