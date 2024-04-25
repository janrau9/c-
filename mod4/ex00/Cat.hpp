/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:31:07 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 08:47:17 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const std::string type);
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        std::string getType() const;
        void setType(const std::string type);

        virtual void makeSound() const;
};

#endif