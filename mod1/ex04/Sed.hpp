/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:45:23 by jberay            #+#    #+#             */
/*   Updated: 2024/04/26 15:12:10 by jberay           ###   ########.fr       */
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
        std::ifstream _infile;
        std::ofstream _outfile;
    public:
        Sed( const std::string file, std::string s1, std::string s2 );
        ~Sed( void );
        std::string* replace( void ); 
        std::string getS1() const;
        std::string getS2() const;
};

#endif