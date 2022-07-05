/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:39:38 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 13:46:25 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Debug.hpp"
#include "LiteralCast.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	std::string	l;

	if ( argc == 2 )
		l = std::string( argv[1] );
	else
		l = std::string( "42" );

	{
		LOG( "test 1: testing LiteralCast Class" );
		LiteralCast	literal = LiteralCast( l );
		std::cout << literal << " type: " << literal.getType() << std::endl;
		literal.printCast();
	}
	return ( 0 );
}
