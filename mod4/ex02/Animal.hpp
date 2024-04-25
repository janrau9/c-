/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:45:17 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 12:05:11 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const std::string type);
        
        virtual ~Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        std::string getType() const;
        void setType(const std::string type);

        virtual void makeSound() const = 0;
};

#endif