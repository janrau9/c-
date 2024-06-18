/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:24:26 by janraub           #+#    #+#             */
/*   Updated: 2024/04/23 20:02:50 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point( void );
        Point(const float x, const float y);
        Point( const Point& other );
        Fixed getX( void ) const;
        Fixed getY( void ) const;
        Point& operator=(const Point& other);
        ~Point( void );
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed area(Point const a, Point const b, Point const c);

#endif