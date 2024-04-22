/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:33:48 by jberay            #+#    #+#             */
/*   Updated: 2024/04/22 11:38:31 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
    std::cout << "Human A constructor called" << std::endl;
}

HumanA::~HumanA( void )
{
    std::cout << "Human A deconstructor called" << std::endl;
}

void HumanA::attack( void )
{
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}