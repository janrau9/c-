/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:55 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 10:02:49 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
    : type("Animal")
{
    std::cout <<  this->type << " default constructor called" << std::endl;
}

Animal::Animal(const std::string type)
    : type(type)
{
    std::cout <<  this->type << " constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout <<  this->type << " virtual deconstructor called" << std::endl;
}

Animal::Animal(const Animal& other)
    : type(other.type)
{
    std::cout <<  this->type << " Copy constructor called " << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout <<  this->type << " assignation called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

void Animal::setType(const std::string type)
{
    this->type = type;
}
void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}