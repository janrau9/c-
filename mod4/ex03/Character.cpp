/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:06:11 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 19:31:23 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name(""), _floor()
{
    //std::cout <<  this->_name << " default constructor called" << std::endl;
    _inventory = new AMateria*[4];
    for (size_t i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::Character(const std::string& name) : _name(name), _floor()
{
    //std::cout <<  this->_name << " constructor called" << std::endl;
    _inventory = new AMateria*[4];
    for (size_t i = 0; i < 4; ++i)
        _inventory[i] = NULL;
}

Character::~Character()
{
    //std::cout <<  this->_name << " virtual deconstructor called" << std::endl;
    for (size_t i = 0; i < 4; ++i)
        delete _inventory[i];
    delete [] _inventory;     
}

Character::Character(const Character& other)
{
    _name = other._name;
    if (_floor.head != NULL || other._floor.head != NULL)
    {
        Node* src = other._floor.head->next;
        Node* dest = _floor.head;
        while (src)
        {
            dest->next = new Node(*src);
            dest = dest->next;
            src = src->next;
        }  
    }
    delete [] _inventory;
    _inventory = new AMateria*[4];
    for (size_t i = 0; i < 4; ++i)
        _inventory[i] = other._inventory[i];

    //std::cout <<  this->_name << " Copy constructor called " << std::endl;
    *this = other;
}

Character& Character::operator=(const Character& other)
{
    //std::cout <<  this->_name << " assignation called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        if (_floor.head != NULL || other._floor.head != NULL)
        {
            Node* temp = _floor.head;
            Node* src = other._floor.head->next;
            Node* dest = _floor.head;
            while (temp->next)
            {
                dest->next = new Node(*src);
                dest = dest->next;
                src = src->next;
            }  
        }
        delete [] _inventory;
        _inventory = new AMateria*[4];
        for (size_t i = 0; i < 4; ++i)
            _inventory[i] = other._inventory[i];
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    for (size_t i = 0; i < 4; ++i)
    {
        if (_inventory[i] == NULL)
        {
            _inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx > 4 || _inventory[idx] == NULL)
        return ;
    _floor.append(_inventory[idx]);
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > 4 || _inventory[idx] == NULL)
        return ;
    _inventory[idx]->use(target);
}