/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:07:56 by jberay            #+#    #+#             */
/*   Updated: 2024/04/26 15:09:57 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed( const std::string file, std::string s1, std::string s2 ) : _s1(s1), _s2(s2)
{
    this->_infile.open(file, std::fstream::in);
    if (this->_infile.fail())
    {
         std::cout << "Failed to open file" << std::endl;
         return ;
    }
    std::string out = file.substr(0, file.find_first_of("."));
    this->_outfile.open(out + ".replace", std::fstream::out | std::fstream::trunc);
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