/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 17:28:46 by mlancac          ###   ########.fr       */
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
		LOG( "test 2: testing inheritance" );
		ClapTrap	clap = ClapTrap( "Clap" );
		ScavTrap	scav = ScavTrap( "Scav" );
		FragTrap	frag = FragTrap( "Frag" );

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
