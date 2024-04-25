/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:54:51 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:50:17 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOUCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "Cure.hpp"
# include "Ice.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria** _inventory;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);
        virtual ~MateriaSource();
            
        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};

#endif