/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:06:13 by jberay            #+#    #+#             */
/*   Updated: 2024/04/17 11:13:45 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class Phonebook
{
    private:
        Contact _contacts[MAX_CONTACTS];
        int _contact_count;
        void add_contact(Contact contact);
        void display_contacts();
        void display_contact(int index);
    public:
        Phonebook();
        void open();
};
#endif