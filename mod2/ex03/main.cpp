/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:19:31 by janraub           #+#    #+#             */
/*   Updated: 2024/04/23 20:36:33 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>

int main( void )
{
    Point const a(0, 0);
    Point const b(10, 20);
    Point const c(20, 0);
    Point p = a;
    std::cout << bsp(a, b, c, p) << std::endl;
    p = b;
    std::cout << bsp(a, b, c, p) << std::endl;
    p = c;
    std::cout << bsp(a, b, c, p) << std::endl;
    Point const i(10, 10);
    std::cout << bsp(a, b, c, i) << std::endl;

    return 0;
}

