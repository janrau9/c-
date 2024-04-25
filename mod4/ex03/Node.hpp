/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:49:14 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:28:19 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>
# include <string>

class Node
{
    public:
        void *content;
        Node *next;
        Node();
        Node(void* content);
        ~Node();
        Node(const Node& other);
        Node& operator=(const Node& other);
};

#endif