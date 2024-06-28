/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jberay <jberay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:14:07 by janraub           #+#    #+#             */
/*   Updated: 2024/06/28 14:58:00 by jberay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"


int main()
{
	std::cout << "==Creating MateriaSource and learning new mats==" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(NULL);
	Character* me = new Character("me");
	AMateria* tmp;
	
	std::cout << std::endl << "==Equipping==" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = NULL;
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");

	std::cout << std::endl << "==Using materias==" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "==Unequipping one materia, put down to floor to be copied/assigned==" << std::endl;
	me->unequip(2);
	me->unequip(1);
	me->unequip(5); //nothing happens, 5 doesn't exist

	//Unequipped 2x Cure
	//Equppied Ice on Slot 0
	//did you find out which one is not freed? 
	//maybe not, 

	std::cout << std::endl << "==Copying character==" << std::endl;
	Character* copy = new Character(*me);

	std::cout << std::endl << "==Assign character prepare==" << std::endl;
	Character* meass = new Character();
	meass->equip(src->createMateria("ice"));
	meass->equip(src->createMateria("cure"));
	meass->unequip(0);
	meass->unequip(1);
	meass->equip(src->createMateria("ice"));
	meass->equip(src->createMateria("cure"));
	meass->equip(src->createMateria("cure"));

	std::cout << std::endl << "==Assign character==" << std::endl;
	*meass = *me;

	std::cout << std::endl << "==Copy actions==" << std::endl;
	copy->use(0, *bob);
	copy->equip(src->createMateria("ice"));
	copy->use(2, *bob);
	copy->unequip(1);
	
	std::cout << std::endl << "==Assigned actions==" << std::endl;
	meass->use(0, *bob);
	meass->equip(src->createMateria("ice"));
	meass->use(2, *bob);
	meass->unequip(1);

	std::cout << std::endl << "==Unequipping==" << std::endl;
	me->unequip(1);
	me->unequip(0);

	std::cout << std::endl << "==Deleting Bob==" << std::endl;
	delete bob;
	std::cout << std::endl << "==Deleting Me==" << std::endl;
	delete me;
	std::cout << std::endl << "==Deleting Copy==" << std::endl;
	delete copy;
	std::cout << std::endl << "==Deleting Assigned==" << std::endl;
	delete meass;
	std::cout << std::endl << "==Deleting MateriaSource==" << std::endl;
	delete src;
	

	return 0;
}
	