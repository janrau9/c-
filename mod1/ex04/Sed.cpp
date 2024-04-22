/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:07:56 by jberay            #+#    #+#             */
/*   Updated: 2024/04/22 17:32:30 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed( const std::string file, std::string s1, std::string s2 ) : _s1(s1), _s2(s2)
{
    this->_infile.open(file, std::fstream::in);
    if (this->_infile.fail())
    {
         std::cout << "Failed to open file" << std::endl;
    }
    this->_outfile.open("filename.replace", std::fstream::out | std::fstream::trunc);
    if (this->_outfile.fail())
    {
         std::cout << "Failed to create file" << std::endl;
    }
}

Sed::~Sed( void )
{
    if (this->_infile.is_open())
        this->_infile.close();
    if (this->_outfile.is_open())
        this->_outfile.close();
}

std::string Sed::getS1() const
{
    return(this->_s1);
}

std::string Sed::getS2() const
{
    return(this->_s2);
}

// std::fstream Sed::getInfile()
// {
//     return(this->_infile);
// }

std::string* Sed::replace( void )
{
    std::string line;
    std::size_t pos;
    std::string s1 = getS1();
    std::string str;

    while (std::getline( this->_infile, line))
    {
        pos = line.find(s1, 0);
        while (pos != std::string::npos)
        {
            this->_outfile << line.substr(0, pos);
            this->_outfile << getS2();
            line = line.substr(pos + s1.length(), line.length() - pos - s1.length());
            pos = line.find(s1, 0);
        }
        this->_outfile << line << std::endl;
    }
    return (NULL);
}