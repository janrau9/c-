/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:55:55 by jberay            #+#    #+#             */
/*   Updated: 2024/11/18 10:19:30 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		std::cout << "Creating forms" << std::endl;

		Form a("a", 1, 1);
		std::cout << a << std::endl;
		Form b("b", 150 , 150);
		std::cout << b << std::endl;
		Form c(a);
		Form d = b;

		std::cout << "####################" << std::endl;
		std::cout << "Creating illegal forms" << std::endl;

		try
		{
			Form i("i", 0, 0);
			std::cout << a << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			Form j("j", 151 , 151);
			std::cout << b << std::endl;	
		}
		catch(const std::exception& e)
		{	
			std::cerr << e.what() << std::endl;
		}

		std::cout << std::endl << "####################" << std::endl;
		std::cout << "Signing forms" << std::endl;

		try
		{
			jan.signForm(a);
			jan.signForm(b);
			rau.signForm(c);
			rau.signForm(d);
			jan.signForm(a);
		}
		catch(const std::exception& e)
		{	
			std::cerr << e.what() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}