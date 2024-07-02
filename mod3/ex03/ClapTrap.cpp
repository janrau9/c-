/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:55 by janraub           #+#    #+#             */
/*   Updated: 2024/07/01 11:40:33 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "Constructor " << this->name << " called" << std::endl;
}

ClapTrap::ClapTrap()
    : name(""), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "Default constructor " << this->name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "deconstructor " << this->name << " called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : name(other.name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage)
{
    std::cout << "Copy constructor called " << std::endl;
    *this = other;
}

ClapTrap::ClapTrap(std::string name, const unsigned int HP, const unsigned int EP,const unsigned int AD)
    : name(name), HitPoints(HP), EnergyPoints(EP), AttackDamage(AD)
{
    std::cout << "Constructor " << this->name << " called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Assignation called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    return (*this);
}

std::string ClapTrap::getName() const
{
    return (this->name);
}

unsigned int ClapTrap::getHP() const
{
    return (this->HitPoints);
}

unsigned int ClapTrap::getEP() const
{
    return (this->EnergyPoints);
}

unsigned int ClapTrap::getAD() const
{
    return (this->AttackDamage);
}

void ClapTrap::setName(const std::string name)
{
    this->name = name;
}

void ClapTrap::setHP(const unsigned int HP)
{
    this->HitPoints = HP;
}

void ClapTrap::setEP(const unsigned int EP)
{
    this->EnergyPoints = EP;
}

void ClapTrap::setAD(const unsigned int AD)
{
    this->AttackDamage = AD;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->EnergyPoints == 0)
    {
        std::cout << "No Energy points left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
    this->EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << "ClapTrap " << this->name << " took " << amount << " damage!" << std::endl;
    this->HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->EnergyPoints == 0)
    {
        std::cout << "No Energy points left" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->name << " has been repaired " << amount << " Hit Points!" << std::endl;
    this->HitPoints += amount;
    this->EnergyPoints--;
}