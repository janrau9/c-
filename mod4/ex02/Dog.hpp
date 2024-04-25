/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:23:24 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 10:00:24 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* _brain;
    public:
        Dog();
        Dog(const std::string type);
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        std::string getType() const;
        Brain* getBrain() const;
        void setBrain(Brain* brain);
        void setType(const std::string type);

        virtual void makeSound() const;
};

#endif