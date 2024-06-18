/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:28:27 by janraub           #+#    #+#             */
/*   Updated: 2024/04/23 20:31:47 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : x(0), y(0)
{
}

Point::Point(const float x, const float y) : x(x), y(y)
{
}

Point::Point( const Point& other) : x(other.getX()), y(other.getY()) 
{
    *this = other;
}

Fixed Point::getX( void ) const
{
    return (this->x);
}

Fixed Point::getY( void ) const
{
    return (this->y);
}

Point& Point::operator=(const Point& other)
{
   (void)other;
    return (*this); 
}

Point::~Point( void )
{
}