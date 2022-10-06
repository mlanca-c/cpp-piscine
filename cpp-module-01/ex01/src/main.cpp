/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:43:48 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:39:21 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	std::string	name;

	if ( argc == 2 )
		name = std::string( argv[1] );
	else
		name = "z";
	Zombie*		horde;

	{
		LOG( "test 1: 1 Zombie" );
		horde = zombieHorde( 1, name );

		for ( int i = 0; i < 1; i++ ) {
			horde[i].anounce();
		}

		delete [] horde;
	}
	{
		LOG( "test 2: 42 Zombies" );
		horde = zombieHorde( 42, name );

		for ( int i = 0; i < 42; i++ ) {
			horde[i].anounce();
		}

		delete [] horde;
	}
	{
		LOG( "test 3: 0 Zombies" );
		horde = zombieHorde( 0, name );
	}
	{
		LOG( "test 4: -2 Zombies" );
		horde = zombieHorde( -2, name );
	}

	return ( 0 );
}
