/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:52 by janraub           #+#    #+#             */
/*   Updated: 2024/04/24 20:12:43 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap a("Hero");
    FragTrap b(a);
    FragTrap c("Alien");

    std::cout << a.getHP() << std::endl;
    a.attack("Hero villain");
    a.beRepaired(10);
    std::cout << a.getHP() << std::endl;;
    a.takeDamage(10);
    std::cout << a.getHP() << std::endl;
    for (int i = 0; i < 10; i++)
        a.beRepaired(10);
    std::cout << a.getHP() << std::endl;
    a.highFivesGuys();
    std::cout << b.getHP() << std::endl;
    b.attack("Alien villain");
    b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.takeDamage(10);
    std::cout << b.getHP() << std::endl;
    for (int i = 0; i < 10; i++)
        b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.highFivesGuys();
    c = b;
    c.beRepaired(10);
   return (0);
}