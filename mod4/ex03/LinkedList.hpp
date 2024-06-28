/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LinkedList.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:02:50 by janraub           #+#    #+#             */
/*   Updated: 2024/06/28 09:34:18 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_HPP
# define LINKEDLIST_HPP

# include "AMateria.hpp"
# include "Node.hpp"

class Node;
class AMateria;

class LinkedList
{
		private:
				Node* head;
		public:
				LinkedList();
				~LinkedList();
				LinkedList(const LinkedList& other);
				LinkedList& operator=(const LinkedList& other);
				void append(AMateria *content);
};

#endif