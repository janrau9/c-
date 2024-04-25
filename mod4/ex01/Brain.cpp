/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:28:37 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 11:50:54 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (size_t i = 0; i < 100; ++i)
            this->ideas[i] = "";
    std::cout << "Brain default constructor called" << std::endl;
}


Brain::~Brain()
{
    std::cout <<  "Brain deconstructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain Copy constructor called " << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout <<  "Brain assignation called" << std::endl;
    if (this != &other)
    {
        for (size_t i = 0; i < 100; ++i)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

void Brain::setIdea(size_t index, std::string idea)
{
    if (index > 100)
        return ;
    this->ideas[index] = idea;
}

std::string Brain::getIdea(size_t index) const
{
    if (index > 100)
        return ("");
    return (this->ideas[index]);
}