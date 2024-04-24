/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:52 by janraub           #+#    #+#             */
/*   Updated: 2024/04/24 20:13:30 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap a("Hero");
    
    std::cout << a.getHP() << std::endl;
    a.attack();
    a.whoAmI();
    a.beRepaired(10);
    std::cout << a.getHP() << std::endl;;
    a.takeDamage(10);
    std::cout << a.getHP() << std::endl;
    for (int i = 0; i < 10; i++)
        a.beRepaired(10);
    std::cout << a.getHP() << std::endl;
    a.highFivesGuys();
    a.guardGate();

    DiamondTrap b(a);
    std::cout << b.getHP() << std::endl;
    b.attack();
    a.whoAmI();
    b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.takeDamage(10);
    std::cout << b.getHP() << std::endl;
    for (int i = 0; i < 10; i++)
        b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.highFivesGuys();
    b.guardGate();

    DiamondTrap c("Alien");
    c = b;
    c.attack();
    c.beRepaired(10);
    c.highFivesGuys();
    c.whoAmI();
    c.takeDamage(10);
    c.guardGate();
   return (0);
}