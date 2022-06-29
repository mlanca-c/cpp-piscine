/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:36:14 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/28 15:19:20 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing the Zombie class" );
		Zombie	z = Zombie( "z" );

		z.anounce();
	}
	{

		LOG( "test 2: testing randomChump and newZombie functions" );
		Zombie	z = Zombie( "z" );
		Zombie*	newZ;

		newZ = newZombie( "new z" );
		newZ->anounce();
		delete newZ;

		z.anounce();

		randomChump( "random z" );
	}

	return (0);
}
