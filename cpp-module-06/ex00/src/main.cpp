/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 19:02:11 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 19:49:58 by mlancac          ###   ########.fr       */
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
		LOG( "test 1: testing cast conversion of scalar types" );
		Literal*	literal = new Literal( str );

		std::cout << *literal << std::endl;
		literal->printValues();

		delete literal;
	}

	return ( 0 );
}
