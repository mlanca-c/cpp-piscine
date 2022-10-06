/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/22 09:28:10 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: basic class testing" );
		DiamondTrap	a = DiamondTrap( "DiamondA" );
		DiamondTrap	b( a );
		DiamondTrap	c;

		c = b;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: let's fight - ROUND 1" );
		DiamondTrap	diamond = DiamondTrap( "Diamond" );
		ClapTrap	clap = ClapTrap( "Clap" );

		std::cout << diamond << std::endl;
		std::cout << clap << std::endl;

		diamond.attack( "Clap" );
		clap.takeDamage( diamond.getAttack() );
		std::cout << diamond << std::endl;
		std::cout << clap << std::endl;
	}
	{
		LOG( "test 3: let's fight - ROUND 2" );
		DiamondTrap	diamond = DiamondTrap( "Diamond" );
		ScavTrap	scav = ScavTrap( "Scav" );

		std::cout << diamond << std::endl;
		std::cout << scav << std::endl;

		diamond.attack( "Scav" );
		scav.takeDamage( diamond.getAttack() );
		scav.attack( "Diamond" );
		diamond.takeDamage( scav.getAttack() );
		diamond.attack( "Scav" );
		scav.takeDamage( diamond.getAttack() );
		scav.attack( "Diamond" );
		diamond.takeDamage( scav.getAttack() );
		diamond.attack( "Scav" );
		scav.takeDamage( diamond.getAttack() );
		scav.attack( "Diamond" );
		diamond.takeDamage( scav.getAttack() );
		diamond.attack( "Scav" );
		scav.takeDamage( diamond.getAttack() );
		std::cout << diamond << std::endl;
		std::cout << scav << std::endl;
		diamond.beRepaired( 60 );
	}
	{
		LOG( "test 4: let's fight - ROUND 3" );
		DiamondTrap	diamond = DiamondTrap( "Diamond" );
		FragTrap	frag = FragTrap( "Frag" );

		std::cout << diamond << std::endl;
		std::cout << frag << std::endl;

		diamond.attack( "Frag" );
		frag.takeDamage( diamond.getAttack() );
		frag.attack( "Diamond" );
		diamond.takeDamage( frag.getAttack() );
		diamond.attack( "Frag" );
		frag.takeDamage( diamond.getAttack() );

		std::cout << diamond << std::endl;
		std::cout << frag << std::endl;
	}
	{
		LOG( "test 4: testing whoAmI() function" );
		DiamondTrap	diamond = DiamondTrap( "Diamond" );

		std::cout << diamond << std::endl;
		diamond.whoAmI();
	}
	return ( 0 );
}
