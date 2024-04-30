/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:19:31 by janraub           #+#    #+#             */
/*   Updated: 2024/04/30 09:59:04 by jberay           ###   ########.fr       */
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
    std::cout << "point at vertex" << std::endl;
    Point p = a;
    std::cout << bsp(a, b, c, p) << std::endl;
    p = b;
    std::cout << bsp(a, b, c, p) << std::endl;
    p = c;
    std::cout << bsp(a, b, c, p) << std::endl;
    std::cout << "point at edge" << std::endl;
    Point const e(10, 0);
    std::cout << bsp(a, b, c, e) << std::endl;
    std::cout << "point outside" << std::endl;
    Point const o(0, 5);
    std::cout << bsp(a, b, c, e) << std::endl;
    std::cout << "point inside" << std::endl;
    Point const i(10, 10);
    std::cout << bsp(a, b, c, i) << std::endl;

    return 0;
}

