/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:26:29 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 21:01:50 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stdint.h>
#include "Debug.hpp"

struct	Data {
	int		i;
	float	f;
	double	d;
};

uintptr_t	serialize( Data* ptr ) {
	return ( reinterpret_cast<uintptr_t>( ptr ));
}

Data*		deserialize( uintptr_t raw ) {
	return ( reinterpret_cast<Data*>( raw ));
}

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	std::string			str;
	std::stringstream	ss;

	Data	d1 = { 42, 4.2f, -4.2 };

	LOG( "test 1: serialization test" );
	Data*		d2 = NULL;
	uintptr_t	ptr;
	( void )ptr;

	ptr = serialize( &d1 );
	d2 = deserialize( ptr );
	if ( &d1 != d2 ) {

		ERROR( &d1 << " is different than " << d2 );
		return ( 1 );
	}
	std::cout << &d1 << " is equal to " << d2 << std::endl;

	std::cout << "d1: { "
		<< d1.i << ", " << d1.f << ", " << d1.d << " }" << std::endl;
	std::cout << "d2: { "
		<< d2->i << ", " << d2->f << ", " << d2->d << " }" << std::endl;


	return ( 0 );
}
