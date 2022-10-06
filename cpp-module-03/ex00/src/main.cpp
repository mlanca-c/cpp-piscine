/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 12:25:14 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "ClapTrap.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: basic testing" );
		ClapTrap	clapTrap = ClapTrap( "Clap" );

		std::cout << clapTrap << std::endl;
		clapTrap.attack( "a rock" );
		clapTrap.attack( "another rock" );
		clapTrap.attack( "yet another rock" );
		clapTrap.attack( "yet another rock" );
		std::cout << clapTrap << std::endl;
		clapTrap.takeDamage( 42 );
		std::cout << clapTrap << std::endl;
		clapTrap.beRepaired( 12 );
		std::cout << clapTrap << std::endl;
		clapTrap.attack( "yet another rock" );
		std::cout << clapTrap << std::endl;
	}
	{
		LOG( "test 2: running out of energy" );
		ClapTrap	clapTrap = ClapTrap( "Clap" );

		while ( clapTrap.getHit() && clapTrap.getEnergy() )
			clapTrap.attack( "a rock" );
		clapTrap.attack( "a rock" );
		clapTrap.beRepaired( 12 );
	}
	{
		LOG( "test 3: running out of hit points" );
		ClapTrap	clapTrap = ClapTrap( "Clap" );

		clapTrap.takeDamage( 12 );
		clapTrap.attack( "a rock" );
		clapTrap.beRepaired( 10 );
		clapTrap.attack( "a rock" );
	}
	return ( 0 );
}
