/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:36:14 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/26 14:07:48 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	Zombie	z = Zombie( "z" );
	Zombie*	newZ;

	newZ = newZombie( "new z" );
	newZ->anounce();
	delete newZ;

	z.anounce();

	randomChump( "random z" );

	return (0);
}
