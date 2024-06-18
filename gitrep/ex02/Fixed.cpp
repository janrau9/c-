/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:21:03 by janraub           #+#    #+#             */
/*   Updated: 2024/06/18 10:32:56 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//****Constructors****//

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

Fixed::Fixed( const Fixed& other )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

//****Functions****//

float Fixed::toFloat( void ) const
{
    return (float)_whole / ( 1 << this->_frac);
}

int Fixed::toInt( void ) const
{
    return (_whole >> this->_frac);
}

int Fixed::getRawBits() const
{
    return (this->_whole);
}

void Fixed::setRawBits(int const raw)
{
    this->_whole = raw;
}

//****overload****//

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

bool Fixed::operator>(const Fixed& rhs) const
{
    if (this->_whole > rhs._whole)
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& rhs) const
{
    if (this->_whole < rhs._whole)
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& rhs)
{
    if (this->_whole >= rhs._whole)
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& rhs)
{
    if (this->_whole <= rhs._whole)
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& rhs)
{
    if (this->_whole == rhs._whole)
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& rhs)
{
    if (this->_whole != rhs._whole)
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits(this->_whole + rhs._whole);
    return (temp);
}

Fixed Fixed::operator-(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits(this->_whole - rhs._whole);
    return (temp);
}

Fixed Fixed::operator*(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits((this->_whole * rhs._whole) >> this->_frac);
    return (temp);
}

Fixed Fixed::operator/(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits((this->_whole << this->_frac) / rhs._whole);
    return (temp);
}

Fixed& Fixed::operator++(void)
{
    this->_whole++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_whole++;
    return (tmp);
}

Fixed& Fixed::operator--(void)
{
    this->_whole--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_whole--;
    return (tmp);
}

//****non member function****//

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs)
{
    return (lhs < rhs ? lhs : rhs);
}

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
    return (lhs < rhs ? lhs : rhs);
}
Fixed& Fixed::max(Fixed& lhs, Fixed& rhs)
{
    return (lhs > rhs ? lhs : rhs);
}
const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
    return (lhs > rhs ? lhs : rhs);
}