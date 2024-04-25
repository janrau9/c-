/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:31:37 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 09:03:39 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
    : WrongAnimal("WrongCat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string type)
    :   WrongAnimal(type)
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << this->type <<  " deconstructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
    : WrongAnimal(other.type)
{
    std::cout <<  this->type << " copy constructor called " << std::endl;
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    std::cout <<  this->type << " assignation called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string WrongCat::getType() const
{
    return (this->type);
}

void WrongCat::setType(const std::string type)
{
    this->type = type;
}

void WrongCat::makeSound() const
{
    std::cout << "Wrong meow meow meow" << std::endl;
}