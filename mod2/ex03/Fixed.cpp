/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:21:03 by janraub           #+#    #+#             */
/*   Updated: 2024/04/30 09:55:03 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//****Constructors****//

Fixed::Fixed() : _whole(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed( const int whole )
{
    this->_whole = whole * (1 << this->_frac);
}

Fixed::Fixed( const float whole )
{
    this->_whole = roundf(whole * (1 << this->_frac));
}

Fixed::Fixed( const Fixed& other )
{
    *this = other;
}

//****Functions****//

float Fixed::toFloat( void ) const
{
    return (float)(this->getRawBits() / ( 1 >> this->_frac));
}

int Fixed::toInt( void ) const
{
    return (this->getRawBits() >> this->_frac);
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
    if (this != &other)
        this->_whole = other.getRawBits();
    return (*this); 
}

std::ostream& operator<<(std::ostream& os, const Fixed& fp)
{
     // Extract integer and fractional parts
    int integerPart = fp.getRawBits() >> 8;  // Shift right to get integer part
    int fractionalPart = fp.getRawBits() & 0xFF;  // Mask to get fractional part

    // Calculate the floating-point representation
    float value = integerPart + ((float)(fractionalPart) / 256.0f);

    // Insert into the output stream
    os << value;
    return os;
}

bool Fixed::operator>(const Fixed& rhs) const
{
    if (this->_whole > rhs.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<(const Fixed& rhs) const
{
    if (this->_whole < rhs.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator>=(const Fixed& rhs)
{
    if (this->_whole >= rhs.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator<=(const Fixed& rhs)
{
    if (this->_whole <= rhs.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator==(const Fixed& rhs)
{
    if (this->_whole == rhs.getRawBits())
        return (true);
    return (false);
}

bool Fixed::operator!=(const Fixed& rhs)
{
    if (this->_whole != rhs.getRawBits())
        return (true);
    return (false);
}

Fixed Fixed::operator+(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits(this->_whole + rhs.getRawBits());
    return (temp);
}

Fixed Fixed::operator-(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits(this->_whole - rhs.getRawBits());
    return (temp);
}

Fixed Fixed::operator*(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits((this->_whole * rhs.getRawBits()) >> this->_frac);
    return (temp);
}

Fixed Fixed::operator/(const Fixed& rhs)
{
    Fixed temp;
    temp.setRawBits(this->_whole << this->_frac / rhs.getRawBits());
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