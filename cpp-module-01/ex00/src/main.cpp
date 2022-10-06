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
		LOG( "test 2: testing newZombie Function" );
		Zombie*	newZ;

		newZ = newZombie( "new z" );
		newZ->anounce();
		delete newZ;
	}
	{
		LOG( "test 3: testing randomChump function" );
		randomChump( "random z" );
	}
	{
		LOG( "test 4: testing two functions together" );
		Zombie	z = Zombie( "z" );
		Zombie*	newZ;

		newZ = newZombie( "new z" );
		newZ->anounce();
		delete newZ;

		randomChump( "random z" );
	}
	return (0);
}
