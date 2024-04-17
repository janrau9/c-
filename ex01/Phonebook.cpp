/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:09:09 by jberay            #+#    #+#             */
/*   Updated: 2024/04/17 15:22:20 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_contact_count = 0;
}

void Phonebook::add_contact(Contact contact)
{
	int	i;
	
	i = _contact_count;
	if (this->_contact_count < MAX_CONTACTS)
	{
		while (i > 0)
		{
			this->_contacts[i] = this->_contacts[i - 1];
			i--;
		}
		this->_contacts[i] = contact;
		this->_contact_count++;
	}
}

void	Phonebook::display_contact(int index)
{
	std::cout << "First name " << _contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << _contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " <<_contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " <<_contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " <<_contacts[index].get_darkest_secret() << std::endl;
}

void    Phonebook::display_contacts()
{
	int 		i;
	std::string	index;

	if (this->_contact_count == 0)
	{
		std::cout << "Empty Phonebook!" << std::endl;
		return ;
	}
	std::cout << std::right;
	std::cout << std::setw(10);
	std::cout << "Index" << "|";
	std::cout << std::right;
	std::cout << std::setw(10);
	std::cout << "First name" << "|";
	std::cout << std::right;
	std::cout << std::setw(10);
	std::cout << "Last name" << "|";
	std::cout << std::right;
	std::cout << std::setw(10);
	std::cout << "Nickname" << std::endl;
	i = -1;
	while (++i < this->_contact_count)
	{
		std::cout << std::right;
		std::cout << std::setw(10);
		std::cout <<  i << "|";
		std::cout << std::right;
		std::cout << std::setw(10);
		std::cout << _contacts[i].get_first_name() << "|";
		std::cout << std::right;
		std::cout << std::setw(10);
		std::cout << _contacts[i].get_last_name() << "|";
		std::cout << std::right;
		std::cout << std::setw(10);
		std::cout << _contacts[i].get_nickname() << std::endl;
	}
	while (1)
	{
		std::cout << "Enter Index: ";
		std::getline(std::cin, index);
		if (!index.empty() && index.find_first_not_of("012345678") != std::string::npos)
		{
			std::cout << "Enter valid index!" << std::endl;
			continue;
		}
		if (atoi(index.c_str()) >= 0 && atoi(index.c_str()) <= this->_contact_count - 1)
		{
			display_contact(atoi(index.c_str()));
			break;
		}
		else
			std::cout << "Enter valid index!" << std::endl;
	}
}

void Phonebook::open()
{
	std::string command;
	Contact contact;
	while (1)
	{
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			std::cout << "Enter First name: ";
			std::getline(std::cin, command);
			contact.set_first_name(command);
			std::cout << "Enter Last name: ";
			std::getline(std::cin, command);
			contact.set_last_name(command);
			std::cout << "Enter Nickname: ";
			std::getline(std::cin, command);
			contact.set_nickname(command);
			std::cout << "Enter Phone number: ";
			std::getline(std::cin, command);
			contact.set_phone_number(command);
			std::cout << "Enter Darkest secret: ";
			std::getline(std::cin, command);
			contact.set_darkest_secret(command);
			this->add_contact(contact);
		}
		else if (command == "SEARCH")
			this->display_contacts();
	}
}