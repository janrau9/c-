/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 08:55:55 by jberay            #+#    #+#             */
/*   Updated: 2024/07/04 12:08:15 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
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
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}