/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:55:03 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/03 20:55:04 by mlancac          ###   ########.fr       */
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
