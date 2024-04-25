/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:55 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 09:03:34 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
    : type("WrongAnimal")
{
    std::cout <<  this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type)
    : type(type)
{
    std::cout <<  this->type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout <<  this->type << " virtual deconstructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
    : type(other.type)
{
    std::cout <<  this->type << " Copy constructor called " << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout <<  this->type << " assignation called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::setType(const std::string type)
{
    this->type = type;
}
void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}