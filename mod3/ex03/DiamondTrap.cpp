/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:01:06 by janraub           #+#    #+#             */
/*   Updated: 2024/04/24 20:09:12 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name", FragTrap::getHP(), ScavTrap::getEP(), FragTrap::getAD())
{
    this->name = name;
    std::cout << "DiamondTrap constructor " << this->name << " called " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap deconstructor " << this->getName() << " called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other.getName()), ScavTrap(name), FragTrap(name)
{
    this->name = other.name;
    this->setName(other.getName());
    this->setHP(other.getHP());
    this->setEP(other.getEP());
    this->setAD(other.getAD());
    *this = other;
    std::cout << "DiamondTrap copy constructor called " << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap assignation called " << std::endl;
    if (this != &other)
    {
        this->setName(other.getName());
        this->setHP(other.getHP());
        this->setEP(other.getEP());
        this->setAD(other.getAD());
    }
    return (*this);
}

void DiamondTrap::attack()
{
    ScavTrap::attack();
}

void DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is " << this->name << std::endl;
    std::cout << "My ClapTrap name is " << ClapTrap::getName() << std::endl;
}  