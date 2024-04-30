/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:49:14 by janraub           #+#    #+#             */
/*   Updated: 2024/04/26 08:17:00 by jberay           ###   ########.fr       */
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