/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:53:23 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 16:30:25 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "ClapTrap.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		ClapTrap	clapTrap = ClapTrap( "Clap" );

		std::cout << clapTrap << std::endl;
		clapTrap.attack( "a rock" );
		clapTrap.attack( "another rock" );
		clapTrap.attack( "yet another rock" );
		std::cout << clapTrap << std::endl;
		clapTrap.takeDamage( 42 );
		std::cout << clapTrap << std::endl;
		clapTrap.beRepaired( 12 );
		std::cout << clapTrap << std::endl;
		clapTrap.attack( "yet another rock" );
		std::cout << clapTrap << std::endl;
	}
	return ( 0 );
}
