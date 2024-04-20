/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:04:46 by janraub           #+#    #+#             */
/*   Updated: 2024/04/20 19:17:27 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string name;
    public:
        Zombie( void );
        Zombie( std::string name );
        ~Zombie( void );
        void announce( void );
        void set_name(std::string name);
};

#endif