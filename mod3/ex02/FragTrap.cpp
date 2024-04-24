/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:13:28 by janraub           #+#    #+#             */
/*   Updated: 2024/04/24 20:08:35 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap()
{
    setHP(100);
    setEP(100);
    setAD(30);
    std::cout << "FragTrap constructor " << this->getName() << " called" << std::endl;
}

FragTrap::FragTrap(std::string name)
    : ClapTrap(name, 100, 100, 30)
{
    std::cout << "FragTrap constructor " << this->getName() << " called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap deconstructor " << this->getName() << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other.getName(), other.getHP(), other.getEP(), other.getAD())
{
    std::cout << "FragTrap copy constructor called " << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap assignation called " << std::endl;
    if (this != &other)
    {
        this->setName(other.getName());
        this->setHP(other.getHP());
        this->setEP(other.getEP());
        this->setAD(other.getAD());
    }
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "Give me a high five guys!" << std::endl;
}