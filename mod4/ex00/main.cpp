/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:52 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 09:11:30 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wmeta = new WrongAnimal();
    std::cout << wmeta->getType() << " " << std::endl;
    wmeta->makeSound();
    const WrongAnimal* w = new WrongCat();
    std::cout << w->getType() << " " << std::endl;
    w->makeSound();

    delete i;
    delete j;
    delete meta;
    delete w;
    delete wmeta;
    return 0;
}
