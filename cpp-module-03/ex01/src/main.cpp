/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 17:13:55 by mlancac          ###   ########.fr       */
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
		LOG( "test 1: testing derived class" );
		ScavTrap	a = ScavTrap( "Scav" );
		ScavTrap	b( a );
		ScavTrap	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: testing inheritance" );
		ClapTrap	clap = ClapTrap( "Clap" );
		ScavTrap	scav = ScavTrap( "Scav" );

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
