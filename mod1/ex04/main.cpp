/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:44:06 by jberay            #+#    #+#             */
/*   Updated: 2024/04/26 15:05:13 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::fstream fs;
        fs.open (argv[1], std::fstream::in);
        fs.close();
        Sed sed(argv[1], argv[2], argv[3]);
        sed.replace();
    }
}