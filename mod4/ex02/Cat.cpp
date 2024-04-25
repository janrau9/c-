/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:31:37 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 11:53:26 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
    : Animal("Cat")
{
    this->_brain = new Brain();
    std::cout << this->type << " default constructor called" << std::endl;
}

Cat::Cat(const std::string type)
    :   Animal(type)
{
    this->_brain = new Brain();
    std::cout << this->type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << this->type <<  " deconstructor called" << std::endl;
}

Cat::Cat(const Cat& other)
    : Animal(other.type)
{
    std::cout <<  this->type << " copy constructor called " << std::endl;
    _brain = new Brain(*other._brain);
    *this = other;
}

Cat& Cat::operator=(const Cat& other)
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

std::string Cat::getType() const
{
    return (this->type);
}

Brain* Cat::getBrain() const
{
    return (this->_brain);
}

void Cat::setBrain(Brain* brain)
{
    this->_brain = brain;
}

void Cat::setType(const std::string type)
{
    this->type = type;
}

void Cat::makeSound() const
{
    std::cout << "meow meow meow" << std::endl;
}