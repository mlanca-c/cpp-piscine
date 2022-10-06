/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/20 11:23:45 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "ClapTrap.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: basic class testing" );
		ClapTrap	a = ClapTrap( "A" );
		ClapTrap	b( a );
		ClapTrap	c;

		c = b;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: basic testing" );
		ClapTrap	clapTrap = ClapTrap( "Clap" );

		std::cout << clapTrap << std::endl;
		clapTrap.attack( "a rock" );
		std::cout << clapTrap << std::endl;

		for ( int i = 0; i < 9; i++ )
			clapTrap.attack( "another rock" );
		std::cout << clapTrap << std::endl;

		clapTrap.takeDamage( 42 );
		std::cout << clapTrap << std::endl;
		clapTrap.beRepaired( 12 );
		std::cout << clapTrap << std::endl;
	}
	{
		LOG( "test 3: running out of energy" );
		ClapTrap	clapTrap = ClapTrap( "Clap" );

		while ( clapTrap.getHit() && clapTrap.getEnergy() )
			clapTrap.attack( "a rock" );
		clapTrap.attack( "a rock" );
		clapTrap.beRepaired( 12 );
	}
	{
		LOG( "test 4: running out of hit points" );
		ClapTrap	clapTrap = ClapTrap( "Clap" );

		clapTrap.takeDamage( 2 );
		std::cout << clapTrap << std::endl;
		clapTrap.takeDamage( 10 );
		std::cout << clapTrap << std::endl;
		clapTrap.takeDamage( 11 );
		clapTrap.attack( "a rock" );
		clapTrap.beRepaired( 10 );
	}
	return ( 0 );
}
