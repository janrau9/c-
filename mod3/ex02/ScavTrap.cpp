/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:46:11 by janraub           #+#    #+#             */
/*   Updated: 2024/04/24 19:57:41 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap()
{
    setHP(100);
    setEP(50);
    setAD(20);
    std::cout << "Default Scavtrap constructor " << this->getName() << " called" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "Scavtrap constructor " << this->getName() << " called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap deconstructor " << this->getName() << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other.getName(), other.getHP(), other.getEP(), other.getAD())
{
    std::cout << "Scavtrap copy constructor called " << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Scavtrap assignation called " << std::endl;
    if (this != &other)
    {
        this->setName(other.getName());
        this->setHP(other.getHP());
        this->setEP(other.getEP());
        this->setAD(other.getAD());
    }
    return (*this);
}

void ScavTrap::attack()
{
    if (this->getEP() == 0)
    {
        std::cout << "ScavTrap has No Energy points left" << std::endl;
        return;
    }
    std::cout << "ScavTrap attacks" << std::endl;
    this->setEP(this->getEP() - 1);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode" << std::endl;    
}