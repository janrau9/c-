/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:05:25 by janraub           #+#    #+#             */
/*   Updated: 2024/06/28 14:56:33 by jberay           ###   ########.fr       */
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
    std::cout <<  "LinkedList deconstructor called" << std::endl;
    Node* temp;
    Node* ptr = head;
    while (ptr)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    head = nullptr;
}

LinkedList::LinkedList(const LinkedList& other) : head(NULL)
{
    if (other.head)
    {
        Node* temp = other.head;
        while (temp)
        {
            this->append(other.head->content->clone());
            temp = temp->next;
        }
    }
    // std::cout << "Copy constructor called " << std::endl;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    // std::cout <<  "assignation called" << std::endl;
    if (this != &other)
    {
        Node* temp;
        Node* ptr = head;
        while (ptr)
        {
            temp = ptr;
            ptr = temp->next;
            delete temp;
        }
        head = nullptr;
        temp = other.head;
        while (temp)
        {
            this->append(other.head->content->clone());
            temp = temp->next;
        }
    }
    return (*this);
}

void LinkedList::append(AMateria *content)
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