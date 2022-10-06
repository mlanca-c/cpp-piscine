/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 13:04:23 by mlanca-c         ###   ########.fr       */
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
		LOG( "test 1: testing derived class" );
		FragTrap	a = FragTrap( "Scav" );
		FragTrap	b( a );
		FragTrap	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: testing diamond inheritance" );
		ClapTrap	clap = ClapTrap( "Clap" );
		ScavTrap	scav = ScavTrap( "Scav" );
		FragTrap	frag = FragTrap( "Frag" );
		DiamondTrap	diamond = DiamondTrap( "diamond" );

		std::cout << diamond << std::endl;
		diamond.attack( "a rock" );
		diamond.attack( "another rock" );
		diamond.attack( "yet another rock" );
		std::cout << diamond << std::endl;
		diamond.takeDamage( 42 );
		std::cout << diamond << std::endl;
		diamond.beRepaired( 12 );
		std::cout << diamond << std::endl;
		diamond.attack( "yet another rock" );
		diamond.highFiveGuys();
		diamond.whoAmI();
		std::cout << diamond << std::endl;
		std::cout << std::endl;

		std::cout << scav << std::endl;
		scav.attack( "a rock" );
		scav.attack( "another rock" );
		scav.attack( "yet another rock" );
		std::cout << scav << std::endl;
		scav.takeDamage( 42 );
		std::cout << scav << std::endl;
		scav.beRepaired( 12 );
		std::cout << scav << std::endl;
		scav.attack( "yet another rock" );
		scav.guardGate();
		std::cout << scav << std::endl;
		std::cout << std::endl;

		std::cout << frag << std::endl;
		frag.attack( "a rock" );
		frag.attack( "another rock" );
		frag.attack( "yet another rock" );
		std::cout << frag << std::endl;
		frag.takeDamage( 42 );
		std::cout << frag << std::endl;
		frag.beRepaired( 12 );
		std::cout << frag << std::endl;
		frag.attack( "yet another rock" );
		frag.highFiveGuys();
		std::cout << frag << std::endl;
		std::cout << std::endl;

		std::cout << clap << std::endl;
		clap.attack( "a rock" );
		clap.attack( "another rock" );
		clap.attack( "yet another rock" );
		std::cout << clap << std::endl;
		clap.takeDamage( 42 );
		std::cout << clap << std::endl;
		clap.beRepaired( 12 );
		std::cout << clap << std::endl;
		clap.attack( "yet another rock" );
		std::cout << clap << std::endl;
	}
	return ( 0 );
}
