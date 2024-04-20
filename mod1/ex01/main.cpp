/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:37:07 by janraub           #+#    #+#             */
/*   Updated: 2024/04/20 19:26:08 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
    Zombie *patient = zombieHorde(5, "zero");
    for (int i = 0; i < 5; i++)
    {
        patient[i].announce();
    }
    delete [] patient;
    return (0);
}