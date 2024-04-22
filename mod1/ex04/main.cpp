/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:44:06 by jberay            #+#    #+#             */
/*   Updated: 2024/04/22 17:37:37 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(void)
{
    std::fstream fs;
    fs.open ("test.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
    fs << "more lorem ipsum lorem hello" << std::endl;
    fs << "more lorem ipsum lorem hello" << std::endl;
    fs.close();
    Sed sed("test.txt", " ", "...");
    sed.replace();
}