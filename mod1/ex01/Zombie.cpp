/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:27:35 by janraub           #+#    #+#             */
/*   Updated: 2024/04/20 19:17:40 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << ": aaahhhh no brain!" << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}