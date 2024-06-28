/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:49:14 by janraub           #+#    #+#             */
/*   Updated: 2024/06/28 09:24:31 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class AMateria;

class Node
{
    public:
        AMateria *content;
        Node *next;
        Node();
        Node(AMateria* content);
        ~Node();
        Node(const Node& other);
        Node& operator=(const Node& other);
};

#endif