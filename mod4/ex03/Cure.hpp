/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:46:49 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:48:14 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string const & type);
        virtual ~Cure();
        Cure(const Cure& other);
        Cure& operator=(const Cure& other);
        
        void setType(std::string const type);
        std::string const & getType() const; //Returns the materia type
        virtual Cure* clone() const;
        virtual void use(ICharacter& target);
};

#endif