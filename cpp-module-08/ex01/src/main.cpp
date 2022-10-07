/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:20:27 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/07 15:12:50 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Span.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing the Span Class" );
		try {
			Span	a( 2 );
			Span	b( a );
			Span	c( 2 );

			b.addNumber( 1 );
			b.addNumber( 2 );
			c = b;
			std::cout << "a: " << a << std::endl;
			std::cout << "b: " << b << std::endl;
			std::cout << "c: " << c << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
	}
	{
		LOG( "test 2: testing addNumber method" );
		try {
			Span	a( 2 );

			a.addNumber( 1 );
			a.addNumber( 2 );
			std::cout << a[0] << std::endl;
			std::cout << a[1] << std::endl;
			a.addNumber( 2 );
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
	}
	{
		LOG( "test 3: testing operator[] method" );
		try {
			Span	a( 2 );

			std::cout << a[0] << std::endl;
			std::cout << a << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
	}
	{
		LOG( "test 4: testing addRandomNumber method" );
		try {
			Span	a( 2 );

			a.addRandomNumber( 30 );
			std::cout << a << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
		try {
			Span	a( 30 );

			a.addRandomNumber( 30 );
			std::cout << a << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
	}
	{
		LOG( "test 5: testing longestSpan and shortestSpan" );
		try {
			Span	a( 10 );

			a.addRandomNumber( 1 );
			std::cout << a << std::endl;
			std::cout << "longest: " << a.longestSpan() << std::endl;
			std::cout << "shortest: " << a.shortestSpan() << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
		try {
			Span	a( 10 );

			a.addRandomNumber( 10 );
			std::cout << a << std::endl;
			std::cout << "longest: " << a.longestSpan() << std::endl;
			std::cout << "shortest: " << a.shortestSpan() << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
		try {
			Span	a( 5 );

			a.addNumber( 2 );
			a.addNumber( 12 );
			a.addNumber( 3 );
			a.addNumber( 5 );
			a.addNumber( 8 );
			std::cout << a << std::endl;
			std::cout << "longest: " << a.longestSpan() << std::endl;
			std::cout << "shortest: " << a.shortestSpan() << std::endl;
		}
		catch ( std::exception& e ) { std::cout << e.what() << std::endl; }
	}
	return ( 0 );
}
