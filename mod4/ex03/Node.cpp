/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:55:13 by janraub           #+#    #+#             */
/*   Updated: 2024/06/28 14:45:00 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Node.hpp"

Node::Node()
    : content(NULL), next(NULL)
{
    //std::cout << "Node default constructor called" << std::endl;
}

Node::Node(AMateria* content)
    : content(content), next(NULL)
{
    //std::cout << "Node default constructor called" << std::endl;
}

Node::~Node()
{
    std::cout <<  "Node deconstructor called" << std::endl;
    if (content)
        delete content;
}

Node::Node(const Node& other)
    : content(other.content), next(other.next)
{
    //std::cout << "Copy constructor called " << std::endl;
}

Node& Node::operator=(const Node& other)
{
    //std::cout <<  "assignation called" << std::endl;
    if (this != &other)
    {
        this->content = other.content;
        this->next = other.next;
    }
    return (*this);
}