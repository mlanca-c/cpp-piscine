/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/22 09:39:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: basic class testing" );
		ScavTrap	a = ScavTrap( "ScavA" );
		ScavTrap	b( a );
		ScavTrap	c;

		c = b;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: let's fight - ROUND 1" );
		ScavTrap	scav = ScavTrap( "Scav" );
		ClapTrap	clap = ClapTrap( "Clap" );

		std::cout << scav << std::endl;
		std::cout << clap << std::endl;

		clap.attack( "Scav" );
		scav.attack( "Clap" );
		clap.takeDamage( scav.getAttack() );
		std::cout << scav << std::endl;
		std::cout << clap << std::endl;
	}
	{
		LOG( "test 3: testing Gate Keeper Mode" );
		ScavTrap	scav = ScavTrap( "Scav" );

		std::cout << scav << std::endl;
		scav.guardGate();
		scav.attack( "a rock" );
		scav.beRepaired( 12 );
		scav.guardGate();
		scav.attack( "a rock" );
		std::cout << scav << std::endl;
	}
	return ( 0 );
}
