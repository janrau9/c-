/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:38:10 by jberay            #+#    #+#             */
/*   Updated: 2024/04/26 15:01:10 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name) : _name(name), _weapon( NULL )
{
    std::cout << "Human B constructor called" << std::endl;
}

HumanB::~HumanB( void )
{
    std::cout << "Human B deconstructor called" << std::endl;
}

void HumanB::attack( void )
{
    if (!_weapon)
        std::cout << this->_name << " attacks with their " << "nothing" << std::endl;
    else
        std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;        
}

void HumanB::setWeapon( Weapon& weapon )
{
    this->_weapon = &weapon;
}