/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janraub <janraub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:28:52 by janraub           #+#    #+#             */
/*   Updated: 2024/04/25 12:10:44 by janraub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"



int main()
{
    
    std::cout << std::endl;
    std::cout << "#Default##" << std::endl;
    const Animal* def = new Animal();
    delete def;
    

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
    
    std::cout << std::endl;
    std::cout << "#dog get and set ideas##" << std::endl;
    Dog* d = new Dog();
    std::cout << "idea: " << d->getBrain()->getIdea(0) << std::endl;
    d->getBrain()->setIdea(0, "let us play!");
    std::cout << "idea: " << d->getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "#copy##" << std::endl;
    Dog* cd = new Dog(*d);
    std::cout << "idea: " << cd->getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "#assignation##" << std::endl;

    Dog* dass = new Dog();
    *cd = *dass; 
    std::cout << "idea: " << cd->getBrain()->getIdea(0) << std::endl;
    
    delete d;
    delete cd;
    delete dass;
    
    std::cout << std::endl;
    std::cout << "#cat get and set ideas##" << std::endl;
    Cat* c = new Cat();
    std::cout << "idea: " << c->getBrain()->getIdea(0) << std::endl;
    c->getBrain()->setIdea(0, "F off!");
    std::cout << "idea: " << c->getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "#copy##" << std::endl;
    Cat* cc = new Cat(*c);
    std::cout << "idea: " << cc->getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "#assignation##" << std::endl;

    Cat* cass = new Cat();
    *cc = *cass; 
    std::cout << "idea: " << cc->getBrain()->getIdea(0) << std::endl;

    delete c;
    delete cc;
    delete cass;
    return 0;
}
