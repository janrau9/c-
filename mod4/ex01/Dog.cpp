/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:24:30 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 11:32:48 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
    : Animal("Dog")
{
    this->_brain = new Brain();
    std::cout << this->type << " default constructor called" << std::endl;
}

Dog::Dog(const std::string type)
    :   Animal(type)
{
    this->_brain = new Brain();
    std::cout << this->type << " constructor called" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << this->type <<  " deconstructor called" << std::endl;
}

Dog::Dog(const Dog& other)
    : Animal(other.type)
{
    std::cout <<  this->type << " copy constructor called " << std::endl;
    _brain = new Brain(*other._brain);
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout <<  this->type << " assignation called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
        delete this->_brain;
        this->_brain = new Brain(*other._brain);
    }
    return (*this);
}

std::string Dog::getType() const
{
    return (this->type);
}

Brain* Dog::getBrain() const
{
    return (this->_brain);
}

void Dog::setBrain(Brain* brain)
{
    this->_brain = brain;
}

void Dog::setType(const std::string type)
{
    this->type = type;
}

void Dog::makeSound() const
{
    std::cout << "ahhhhhwoooooo arf arf" << std::endl;
}