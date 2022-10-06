/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:02:11 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 19:03:14 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Literal.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	std::string	str;

	if ( argc != 2 ) { str = std::string( "4.2f" ); }
	else { str = std::string( argv[1] ); }

	{
		LOG( "test 1: testing Literal class" );
		Literal	a( "c" );
		Literal	b( a );
		Literal	c;

		c = b;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 2: testing with " << str );
		Literal	literal( str );

		std::cout << literal << std::endl;
		literal.print();
	}

	return ( 0 );
}
