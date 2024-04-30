/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:52 by janraub           #+#    #+#             */
/*   Updated: 2024/04/30 10:46:58 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main()
{

    // std::cout << std::endl;
    // std::cout << "#Default##" << std::endl;
    // const Animal* def = new Animal();
    // delete def;
    
    const Animal* a[10];

    for (size_t i = 0; i < 10; ++i)
    {
        if (i < 5)
        {
            std::cout << std::endl;
            std::cout << i <<" #constructors#" << std::endl;
            a[i] = new Dog();
        }
        else
        {
            std::cout << std::endl;
            std::cout << i << " #constructors#" << std::endl;
            a[i] = new Cat();
        }
    }
    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << std::endl;
        std::cout << i << " #address#" << std::endl;
        std::cout << &a[i] << std::endl;
    }
    
    for (size_t i = 0; i < 10; ++i)
    {
        std::cout << std::endl;
        std::cout << i << "#deconstructors##" << std::endl;
        delete a[i];
    }
}
