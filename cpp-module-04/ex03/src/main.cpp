/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:03 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/09/27 11:15:07 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing Ice Class" );
		Ice a;
		Ice b( a );
		Ice c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

		AMateria*	ice = new Ice();
		AMateria*	clone = ice->clone();
		std::cout << *ice << std::endl;
		std::cout << *clone << std::endl;
		delete ice;
		delete clone;
	}
	{
		LOG( "test 2: testing Cure Class" );
		Cure a;
		Cure b( a );
		Cure c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

		AMateria*	cure = new Cure();
		AMateria*	clone = cure->clone();
		std::cout << *cure << std::endl;
		std::cout << *clone << std::endl;
		delete cure;
		delete clone;
	}
	{
		LOG("test 3: testing MateriaSource Class" );
		MateriaSource	a;
		MateriaSource	b( a );
		MateriaSource	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

		IMateriaSource*	src = new MateriaSource();
		AMateria*		ice = new Ice();
		AMateria*		cure = new Cure();

		src->learnMateria( ice );
		src->learnMateria( ice );
		ice = src->createMateria( "ice" );
		src->createMateria( "cure" );
		src->learnMateria( cure );
		cure = src->createMateria( "cure" );

		std::cout << "src: " << *(dynamic_cast<MateriaSource*>(src)) << std::endl;
		delete src;
		delete ice;
		delete cure;
	}
	{
		LOG( "test 4: testing Character Class" );
		Character	a( "me" );
		Character	b( a );
		Character	c( "Dave" );

		b.equip( new Ice() );
		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

		ICharacter*	me = new Character( "me" );
		std::cout << "me: " << *(dynamic_cast<Character*>(me)) << std::endl;
		delete me;
	}
	{
		LOG("test 5: testing main from subject");
		IMateriaSource*	src = new MateriaSource();
		ICharacter*		me = new Character( "me" );
		ICharacter*		bob = new Character( "bob" );
		AMateria*		tmp;

		src->learnMateria( new Ice() );
		src->learnMateria( new Cure() );

		tmp = src->createMateria( "ice" );
		me->equip( tmp );

		tmp = src->createMateria( "cure" );
		me->equip( tmp );

		me->use( 0, *bob );
		me->use( 1, *bob );

		delete src;
		delete me;
		delete bob;
	}
	return ( 0 );
}
