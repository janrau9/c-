/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:06:13 by jberay            #+#    #+#             */
/*   Updated: 2024/04/22 09:22:49 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <stdlib.h>

class Phonebook
{
    private:
        Contact _contacts[MAX_CONTACTS];
        int _contact_count;
        void _get_fields(std::string fields, std::string *value);
        void _get_index();
        void _add_contact(Contact contact);
        void _display_contacts();
        std::string _get_short_contact(std::string value);
        void _display_contact(int index);
    public:
        Phonebook();
        void open();
};
#endif