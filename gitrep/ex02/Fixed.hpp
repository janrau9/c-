/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:09:21 by janraub           #+#    #+#             */
/*   Updated: 2024/04/30 09:53:06 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int _whole;
        static int const _frac = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed( const int whole );
        Fixed( const float whole );
        Fixed( const Fixed& other );

        bool operator>(const Fixed& rhs) const;
        bool operator<(const Fixed& rhs) const;
        bool operator>=(const Fixed& rhs);
        bool operator<=(const Fixed& rhs);
        bool operator==(const Fixed& rhs);
        bool operator!=(const Fixed& rhs);

        Fixed operator+(const Fixed& rhs);
        Fixed operator-(const Fixed& rhs);
        Fixed operator*(const Fixed& rhs);
        Fixed operator/(const Fixed& rhs);

        Fixed& operator++(void);
        Fixed operator++(int);
        Fixed& operator--(void);
        Fixed operator--(int);

        static Fixed& min(Fixed& lhs, Fixed& rhs);
        static const Fixed& min(const Fixed& lhs, const Fixed& rhs); 
        static Fixed& max(Fixed& lhs, Fixed& rhs);
        static const Fixed& max(const Fixed& lhs, const Fixed& rhs);
        
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& fp);
#endif