/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:52 by janraub           #+#    #+#             */
/*   Updated: 2024/04/24 12:08:21 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap a("Hero");
    ScavTrap b(a);
    ScavTrap c("Alien");

    std::cout << a.getHP() << std::endl;
    a.attack();
    a.beRepaired(10);
    std::cout << a.getHP() << std::endl;;
    a.takeDamage(10);
    std::cout << a.getHP() << std::endl;
    for (int i = 0; i < 50; i++)
        a.beRepaired(10);
    std::cout << a.getHP() << std::endl;
    a.guardGate();
    std::cout << b.getHP() << std::endl;
    b.attack();
    b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.takeDamage(10);
    std::cout << b.getHP() << std::endl;
    for (int i = 0; i < 50; i++)
        b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.guardGate();
    c = b;
    c.beRepaired(10);
   return (0);
}