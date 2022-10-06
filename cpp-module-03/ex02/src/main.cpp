/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/22 09:37:16 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: basic class testing" );
		FragTrap	a = FragTrap( "FragA" );
		FragTrap	b( a );
		FragTrap	c;

		c = b;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: let's fight - ROUND 1" );
		FragTrap	frag = FragTrap( "Frag" );
		ClapTrap	clap = ClapTrap( "Clap" );

		std::cout << frag << std::endl;
		std::cout << clap << std::endl;

		frag.attack( "Clap" );
		clap.takeDamage( frag.getAttack() );
		std::cout << frag << std::endl;
		std::cout << clap << std::endl;
	}
	{
		LOG( "test 3: let's fight - ROUND 2" );
		FragTrap	frag = FragTrap( "Frag" );
		ScavTrap	scav = ScavTrap( "Scav" );

		std::cout << frag << std::endl;
		std::cout << scav << std::endl;

		scav.attack( "Frag" );
		frag.takeDamage( scav.getAttack() );
		std::cout << frag << std::endl;
		std::cout << scav << std::endl;

		frag.beRepaired( 12 );
		frag.attack( "Scav" );
		scav.takeDamage( frag.getAttack() );
		scav.attack( "Frag" );
		frag.takeDamage( scav.getAttack() );
		std::cout << frag << std::endl;
		std::cout << scav << std::endl;
	}
	{
		LOG( "test 4: testing High Five Guys" );
		FragTrap	frag = FragTrap( "Frag" );

		std::cout << frag << std::endl;
		frag.highFiveGuys();
		for ( int i = 0; i < 100; i++ ) {
			frag.attack( "a rock" );
		}
		frag.highFiveGuys();
		frag.takeDamage( 100 );
		frag.highFiveGuys();
		std::cout << frag << std::endl;
	}
	return ( 0 );
}
