/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:21:25 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/06 12:50:29 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "whatever.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: test ::swap()" );
		int	a = 42;
		int	b = 21;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap<int>( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;

		double	c = 4.2;
		double	d = 2.1;

		std::cout << "c = " << c << ", d = " << d << std::endl;
		::swap<double>( c, d );
		std::cout << "c = " << c << ", d = " << d << std::endl;

		std::string	e = "Hello";
		std::string	f = "World";

		std::cout << "e = " << e << ", f = " << f << std::endl;
		::swap<std::string>( e, f );

		char	g = 'a';
		char	h = 'b';

		std::cout << "g = " << g << ", h = " << h << std::endl;
		::swap<char>( g, h );
		std::cout << "g = " << g << ", h = " << h << std::endl;
	}
	{
		LOG( "test 2: test ::min()" );
		int	a = 42;
		int	b = 21;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;


		double	c = 4.2;
		double	d = 2.1;

		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min<double>( c, d ) << std::endl;

		std::string	e = "Hello";
		std::string	f = "World";

		std::cout << "e = " << e << ", f = " << f << std::endl;
		std::cout << "min( e, f ) = " << ::min<std::string>( e, f ) << std::endl;

		char	g = 'a';
		char	h = 'b';

		std::cout << "g = " << g << ", h = " << h << std::endl;
		std::cout << "min( g, h ) = " << ::min<char>( g, h ) << std::endl;
	}
	{
		LOG( "test 3: test ::max()" );
		int	a = 42;
		int	b = 21;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;


		double	c = 4.2;
		double	d = 2.1;

		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "max( c, d ) = " << ::max<double>( c, d ) << std::endl;

		std::string	e = "Hello";
		std::string	f = "World";

		std::cout << "e = " << e << ", f = " << f << std::endl;
		std::cout << "max( e, f ) = " << ::max<std::string>( e, f ) << std::endl;

		char	g = 'a';
		char	h = 'b';

		std::cout << "g = " << g << ", h = " << h << std::endl;
		std::cout << "max( g, h ) = " << ::max<char>( g, h ) << std::endl;
	}
	{
		LOG( "test 4: test from subject's main" );
		int	a = 2;
		int	b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string	c = "chaine1";
		std::string	d = "chaine2";

		::swap( c, d );
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	return ( 0 );
}
