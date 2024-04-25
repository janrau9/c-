/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:50:16 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:34:25 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        AMateria** _inventory;
        std::string _name;
        LinkedList _floor;
    public:
        Character();
        Character(const std::string& name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        virtual ~Character();
        
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif