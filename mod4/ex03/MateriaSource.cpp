/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:01:42 by janraub           #+#    #+#             */
/*   Updated: 2024/06/28 12:01:04 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    //std::cout <<  this->_name << " default constructor called" << std::endl;
    _inventory = new AMateria*[4];
    for (size_t i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    //std::cout <<  this->_name << " virtual deconstructor called" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        delete _inventory[i];
    delete [] _inventory;     
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    delete [] _inventory;
    _inventory = new AMateria*[4];
    for (size_t i = 0; i < 4; ++i)
        _inventory[i] = other._inventory[i];

    //std::cout <<  this->_name << " Copy constructor called " << std::endl;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
   // std::cout <<  this->_name << " assignation called" << std::endl;
    if (this != &other)
    {
        delete [] _inventory;
        _inventory = new AMateria*[4];
        for (size_t i = 0; i < 4; ++i)
            _inventory[i] = other._inventory[i];
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;
    for (size_t i = 0; i < 4; ++i)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (size_t i = 0; i < 4; ++i)
    {
        if (_inventory[i] && _inventory[i]->getType() == type)
            return (_inventory[i]->clone());
    }
    return (NULL);
}