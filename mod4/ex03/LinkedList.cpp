/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:05:25 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 18:27:46 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LinkedList.hpp"

LinkedList::LinkedList()
    : head(NULL)
{
   // std::cout << "LinkedList default constructor called" << std::endl;
}

LinkedList::~LinkedList()
{
   // std::cout <<  "LinkedList deconstructor called" << std::endl;
    Node* temp = head;
    while (temp)
    {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList& other)
    : head(other.head)
{
    // std::cout << "Copy constructor called " << std::endl;
    *this = other;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    // std::cout <<  "assignation called" << std::endl;
    if (this != &other)
    {
        this->head = other.head;
    }
    return (*this);
}

void LinkedList::append(void *content)
{
    Node* newNode = new Node(content);
    if (!head)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* Node* LinkedList::getHead() const
{
    return (head);
} */