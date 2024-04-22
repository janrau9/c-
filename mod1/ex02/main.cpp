/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:37:07 by janraub           #+#    #+#             */
/*   Updated: 2024/04/22 10:17:29 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
   std::string  string = "HI THIS IS BRAIN";
   std::string* stringPTR = &string;
   std::string& stringREF = string;
   
   std::cout << "Memory address of string via variable string: " << &string << std::endl;
   std::cout << "Memory address of string via variable stringPTR: " << stringPTR << std::endl;
   std::cout << "Memory address of string via variable stringREF: " << &stringREF << std::endl;
  
   std::cout << "Value of string via variable string: " << string << std::endl;
   std::cout << "Value of string via variable stringPTR: " << *stringPTR << std::endl;
   std::cout << "Value of string via variable stringREF: " << stringREF << std::endl;
   
}