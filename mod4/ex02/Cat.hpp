/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:31:07 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 10:01:14 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* _brain;
    public:
        Cat();
        Cat(const std::string type);
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        std::string getType() const;
        Brain* getBrain() const;
        void setBrain(Brain* brain);
        void setType(const std::string type);

        virtual void makeSound() const;
};

#endif