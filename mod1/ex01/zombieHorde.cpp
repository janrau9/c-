/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 19:04:27 by janraub           #+#    #+#             */
/*   Updated: 2024/04/20 19:20:36 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *patient = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        patient[i].set_name(name);
    }
    return (patient);
}