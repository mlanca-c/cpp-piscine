/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:43:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/26 14:50:42 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	Zombie*		horde;

	{
		LOG( "test 1: 1 Zombie" );
		horde = zombieHorde( 1, "z" );

		for ( int i = 0; i < 1; i++ ) {
			horde[i].anounce();
		}

		delete [] horde;
	}
	{
		LOG( "test 2: 42 Zombies" );
		horde = zombieHorde( 42, "z" );

		for ( int i = 0; i < 42; i++ ) {
			horde[i].anounce();
		}

		delete [] horde;
	}
	{
		LOG( "test 3: 0 Zombies" );
		horde = zombieHorde( 0, "z" );

		delete [] horde;
	}
	{
		LOG( "test 4: -2 Zombies" );
		horde = zombieHorde( -2, "z" );

		delete [] horde;
	}

	return ( 0 );
}
