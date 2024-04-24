/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:52 by janraub           #+#    #+#             */
/*   Updated: 2024/04/24 12:09:29 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Hero");
    ClapTrap b(a);
    ClapTrap c("Alien");
    
    a.attack("Villain");
    std::cout << a.getHP() << std::endl;
    a.beRepaired(10);
    std::cout << a.getHP() << std::endl;
    a.takeDamage(10);
    std::cout << a.getHP() << std::endl;
    for (int i = 0; i < 10; i++)
        a.beRepaired(10);
    std::cout << a.getHP() << std::endl;
    a.attack("me");

    std::cout << b.getHP() << std::endl;
    b.attack("Villain");
    b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.takeDamage(10);
    std::cout << b.getHP() << std::endl;
    for (int i = 0; i < 10; i++)
        b.beRepaired(10);
    std::cout << b.getHP() << std::endl;
    b.attack("me");
    c = b;
    c.attack("me");
    
}