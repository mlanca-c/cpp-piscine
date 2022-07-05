/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:06:32 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/05 21:24:37 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Debug.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void );
void	identify( Base* p );
void	identify( Base& p );

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "Test:" );
		Base*	ptr = generate();

		identify( ptr );
		identify( *ptr );

		delete ptr;
	}

	return ( 0 );
}

Base*	generate( void ) {

	srand( time( NULL ));
	int i = rand() % 3;

	if ( i == 0 ) {
		DEBUG( "generated A" );
		return ( new A );
	}
	if ( i == 1 ) {
		DEBUG( "generated B" );
		return ( new B );
	}
	else {
		DEBUG( "generated C" );
		return ( new C );
	}

}

void	identify( Base* ptr ) {

	if ( dynamic_cast<A*>( ptr ))
		std::cout << "identified A" << std::endl;
	else if ( dynamic_cast<B*>( ptr ))
		std::cout << "identified B" << std::endl;
	else if ( dynamic_cast<C*>( ptr ))
		std::cout << "identified C" << std::endl;
	else
		ERROR( "failed identifying derived class" );
}

void	identify( Base& ref ) {

	try {
		A	a = dynamic_cast<A&>( ref );
		( void )a;
		std::cout << "identified A" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}

	try {
		B	b = dynamic_cast<B&>( ref );
		( void )b;
		std::cout << "identified B" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}

	try {
		C	c = dynamic_cast<C&>( ref );
		( void )c;
		std::cout << "identified C" << std::endl;
		return ;
	}
	catch ( std::exception& e ) {}

	ERROR( "failed identifying derived class" );
}
