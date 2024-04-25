/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:46:21 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:48:22 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string const & type);
        virtual ~Ice();
        Ice(const Ice& other);
        Ice& operator=(const Ice& other);
        
        void setType(std::string const type);
        std::string const & getType() const; //Returns the materia type
        virtual Ice* clone() const;
        virtual void use(ICharacter& target);
};

#endif