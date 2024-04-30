/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:55 by janraub           #+#    #+#             */
/*   Updated: 2024/04/26 11:42:49 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
    : type("")
{
    //std::cout <<  this->type << " default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type)
    : type(type)
{
    //std::cout <<  this->type << " constructor called" << std::endl;
}

AMateria::~AMateria()
{
    //std::cout <<  this->type << " virtual deconstructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
    : type(other.type)
{
   // std::cout <<  this->type << " Copy constructor called " << std::endl;
    *this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
   // std::cout <<  this->type << " assignation called" << std::endl;
    (void)other;
    return (*this);
}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::setType(std::string const type)
{
    this->type = type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "AMateria use to " << std::endl;
}