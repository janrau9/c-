/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:55:55 by jberay            #+#    #+#             */
/*   Updated: 2024/08/12 12:00:48 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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

		ShrubberyCreationForm form1("sbform");
		std::cout << "form 1: " << form1 << std::endl;
		
		try
		{
			jan.signForm(form1);
			rau.signForm(form1);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			jan.executeForm(form1);
			rau.executeForm(form1);
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