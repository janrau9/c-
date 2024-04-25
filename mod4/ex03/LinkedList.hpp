/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:02:50 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:27:34 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include "Node.hpp"

class LinkedList
{
    public:
        Node* head;
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);
        void append(void *content);
      //  Node *getHead() const;
};

#endif