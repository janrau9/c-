/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:21:03 by janraub           #+#    #+#             */
/*   Updated: 2024/06/18 10:57:32 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _whole(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const int whole )
{
    std::cout << "Int constructor called" << std::endl;
    this->_whole = whole << this->_frac;
}

Fixed::Fixed( const float whole )
{
    std::cout << "Float constructor called" << std::endl;
    this->_whole = roundf(whole * (1 << this->_frac));
}

float Fixed::toFloat( void ) const
{
    return (float)_whole / ( 1 << this->_frac);
}

int Fixed::toInt( void ) const
{
    return (_whole >> this->_frac);
}

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_whole = other._whole;
    return (*this); 
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
    os << fp.toFloat();
    return os;
}


int Fixed::getRawBits() const
{
    return (this->_whole);
}

void Fixed::setRawBits(int const raw)
{
    this->_whole = raw;
}