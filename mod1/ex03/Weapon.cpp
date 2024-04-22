/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:25:44 by jberay            #+#    #+#             */
/*   Updated: 2024/04/22 11:39:19 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string weapon)
{
    std::cout << "Weapon constructor called" << std::endl;
    this->_type = weapon;
}

Weapon::~Weapon( void )
{
    std::cout << "Weapon deconstructor called" << std::endl;
}

std::string Weapon::getType() const
{
    return (this->_type);
}

void Weapon::setType( std::string type )
{
    this->_type = type;
}