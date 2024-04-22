/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:45:23 by jberay            #+#    #+#             */
/*   Updated: 2024/04/22 17:06:53 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_H
# define SED_H

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
    private:
        std::string const _s1;
        std::string const _s2;
        std::fstream _infile;
        std::fstream _outfile;
    public:
        Sed( const std::string file, std::string s1, std::string s2 );
        ~Sed( void );
        std::string* replace( void ); 
        // std::fstream getInfile();
        // std::fstream getOutfile();
        std::string getS1() const;
        std::string getS2() const;
};

#endif