/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:41:48 by janraub           #+#    #+#             */
/*   Updated: 2024/04/23 20:24:13 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed area(Point const a, Point const b, Point const c)
{
    Fixed tmp1 = (a.getX() * (b.getY() - c.getY()));
    Fixed tmp2 = (b.getX() * (c.getY() - a.getY()));
    Fixed tmp3 = (c.getX() * (a.getY() - b.getY()));
    Fixed two(2);
    Fixed total = (tmp1 + tmp2 + tmp3) / two;
    if (total < 0)
        total = total * -1;
    return (total);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed abc = area(a, b, c);
    Fixed pbc = area(point, b, c);
    Fixed apc = area(a, point, c);
    Fixed abp = area(a, b, point);
    Fixed zero;
    if ( pbc == zero || apc == zero || abp == zero)
        return (false);
    return (abc == pbc + apc + abp);
}