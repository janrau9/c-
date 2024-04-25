/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:37:12 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:59:27 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
    : AMateria("cure")
{
   // std::cout <<  this->type << " default constructor called" << std::endl;
}

Cure::Cure(const std::string& type)
    : AMateria(type)
{
   // std::cout <<  this->type << " constructor called" << std::endl;
}

Cure::~Cure()
{
   // std::cout <<  this->type << " virtual deconstructor called" << std::endl;
}

Cure::Cure(const Cure& other)
    : AMateria(other.type)
{
   // std::cout <<  this->type << " Copy constructor called " << std::endl;
    *this = other;
}

Cure& Cure::operator=(const Cure& other)
{
   // std::cout <<  this->type << " assignation called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string const & Cure::getType() const
{
    return (this->type);
}

void Cure::setType(std::string const type)
{
    this->type = type;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure* Cure::clone() const
{
    return (new Cure(this->type));
}