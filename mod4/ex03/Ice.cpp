/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:49:21 by janraub           #+#    #+#             */
/*   Updated: 2024/04/26 11:51:33 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
    : AMateria("Ice")
{
   // std::cout <<  this->type << " default constructor called" << std::endl;
}

Ice::Ice(const std::string& type)
    : AMateria(type)
{
   // std::cout <<  this->type << " constructor called" << std::endl;
}

Ice::~Ice()
{
    //std::cout <<  this->type << " virtual deconstructor called" << std::endl;
}

Ice::Ice(const Ice& other)
    : AMateria(other.type)
{
   // std::cout <<  this->type << " Copy constructor called " << std::endl;
    *this = other;
}

Ice& Ice::operator=(const Ice& other)
{
    //std::cout <<  this->type << " assignation called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string const & Ice::getType() const
{
    return (this->type);
}

void Ice::setType(std::string const type)
{
    this->type = type;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}

Ice* Ice::clone() const
{
    return (new Ice());
}