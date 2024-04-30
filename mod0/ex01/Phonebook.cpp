/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:09:09 by jberay            #+#    #+#             */
/*   Updated: 2024/04/26 11:06:51 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->_contact_count = 0;
}

void Phonebook::_add_contact(Contact contact)
{
	int	i;
	
	i = MAX_CONTACTS - 1;
	while (i > 0)
	{
		this->_contacts[i] = this->_contacts[i - 1];
		i--;
	}
	this->_contacts[0] = contact;
	if (this->_contact_count < MAX_CONTACTS)
		this->_contact_count++;
}

void	Phonebook::_display_contact(int index)
{
	std::cout << "First name " << this->_contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].get_darkest_secret() << std::endl;
}

void	Phonebook::_get_index()
{
	std::string	index;

	while (1)
	{
		std::cout << "Enter Index: ";
		std::getline(std::cin, index);
		if (std::cin.eof() == true)
			break;
		if (!index.empty() && index.find_first_not_of("012345678") != std::string::npos)
		{
			std::cout << "Enter valid index!" << std::endl;
			continue;
		}
		if (atoi(index.c_str()) >= 0 && atoi(index.c_str()) <= this->_contact_count - 1)
		{
			this->_display_contact(atoi(index.c_str()));
			break;
		}
		else
			std::cout << "Enter valid index!" << std::endl;
	}
}

std::string Phonebook::_get_short_contact(std::string value)
{
	if (value.length() > 10)
		return value.substr(0, 9) + ".";
	return value;
}

void    Phonebook::_display_contacts()
{
	int 		i;

	if (this->_contact_count == 0)
	{
		std::cout << "Empty Phonebook!" << std::endl;
		return ;
	}
	std::cout << std::right << std::setw(10);
	std::cout << "Index" << "|";
	std::cout << std::right << std::setw(10);
	std::cout << "First name" << "|";
	std::cout << std::right << std::setw(10);
	std::cout << "Last name" << "|";
	std::cout << std::right << std::setw(10);
	std::cout << "Nickname" << std::endl;
	i = -1;
	while (++i < this->_contact_count)
	{
		std::cout << std::right << std::setw(10);
		std::cout <<  i << "|";
		std::cout << std::right << std::setw(10);
		std::cout << this->_get_short_contact(_contacts[i].get_first_name()) << "|";
		std::cout << std::right << std::setw(10);
		std::cout << this->_get_short_contact(_contacts[i].get_last_name()) << "|";
		std::cout << std::right << std::setw(10);
		std::cout << this->_get_short_contact(_contacts[i].get_nickname()) << std::endl;
	}
	this->_get_index();
}

void	Phonebook::_get_fields(std::string field, std::string *value)
{
	while (1)
	{
		std::cout << "Enter " << field << ": ";
		std::getline(std::cin, *value);
		if (std::cin.eof() == true)
			break;
		if (!value->empty())
		{
			if (field == "Phone number" && value->find_first_not_of("0123456789") != std::string::npos)
			{
				std::cout << "Enter valid " << field << "!" << std::endl;
				continue;
			}
			break;
		}
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
		if (std::cin.eof() == true)
			break;
		if (command == "EXIT")
			break;
		else if (command == "ADD")
		{
			this->_get_fields("First name", &command);
			contact.set_first_name(command);
			this->_get_fields("Last name", &command);
			contact.set_last_name(command);
			this->_get_fields("Nickname", &command);
			contact.set_nickname(command);
			this->_get_fields("Phone number", &command);
			contact.set_phone_number(command);
			this->_get_fields("Darkest secret", &command);
			contact.set_darkest_secret(command);
			this->_add_contact(contact);
		}
		else if (command == "SEARCH")
			this->_display_contacts();
	}
}
