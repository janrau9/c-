/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:31:37 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 10:02:44 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat")
{
    std::cout << this->type << " default constructor called" << std::endl;
}

Cat::Cat(const std::string type)
    :   Animal(type)
{
    std::cout << this->type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << this->type <<  " deconstructor called" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other.type)
{
    std::cout <<  this->type << " copy constructor called " << std::endl;
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout <<  this->type << " assignation called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return (*this);
}

std::string Cat::getType() const
{
    return (this->type);
}

void Cat::setType(const std::string type)
{
    this->type = type;
}

void Cat::makeSound() const
{
    std::cout << "meow meow meow" << std::endl;
}