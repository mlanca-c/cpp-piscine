/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:26:29 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 19:17:49 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stdint.h>
#include "Debug.hpp"

struct	Data {
	int	x;
	int	y;
};

uintptr_t	serialize( Data* ptr ) {
	return ( reinterpret_cast<uintptr_t>( ptr ));
}

Data*	deserialize( uintptr_t raw ) {
	return ( reinterpret_cast<Data*>( raw ));
}

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	std::string			str;
	std::stringstream	ss;

	Data	d1 = { 2, -4 };

	LOG( "test 1: serialization test" );
	Data*		d2 = NULL;
	uintptr_t	ptr;

	ptr = serialize( &d1 );
	d2 = deserialize( ptr );
	if ( &d1 != d2 ) {

		ERROR( &d1 << " is different than " << d2 );
		return ( 1 );
	}
	std::cout << &d1 << " is equal to " << d2 << std::endl;

	std::cout << "d1: { "
		<< d1.x << ", " << d1.y << " }" << std::endl;
	std::cout << "d2: { "
		<< d2->x << ", " << d2->y << " }" << std::endl;


	return ( 0 );
}
