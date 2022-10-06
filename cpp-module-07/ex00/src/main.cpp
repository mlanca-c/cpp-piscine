/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 12:21:25 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/05 22:28:41 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "whatever.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: test ::swap() with int" );
		int	a = 42;
		int	b = 21;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap<int>( a, b );
		std::cout << "::swap<int>( a, b )" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
	{
		LOG( "test 2: test ::swap() with double" );

		double	a = 4.2;
		double	b = 2.1;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap<double>( a, b );
		std::cout << "::swap<double>( a, b )" << std::endl;
		std::cout << "a = " << a << ", d = " << b << std::endl;
	}
	{
		LOG( "test 3: test ::swap() with std::string" );

		std::string	a = "Hello";
		std::string	b = "World";

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::min<std::string>( a, b );
		std::cout << "::min<std::string>( a, b )" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
	{
		LOG( "test 4: test ::swap() with char" );

		char	a = 'a';
		char	b = 'b';

		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap<char>( a, b );
		std::cout << "::swap<char>( a, b )" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
	{
		LOG( "test 5: test ::min() with int" );
		int	a = 42;
		int	b = 21;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min<int>( a, b ) = " << ::min<int>( a, b ) << std::endl;
	}
	{
		LOG( "test 6: test ::min() with double" );
		double	a = 4.2;
		double	b = 2.1;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min<double>( a, b ) = " << ::min<double>( a, b ) << std::endl;
	}
	{
		LOG( "test 7: test ::min() with std::string" );
		std::string	a = "Hello";
		std::string	b = "World";

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min<std::string>( a, b ) = " << ::min<std::string>( a, b )
				  << std::endl;
	}
	{
		LOG( "test 8: test ::min() with char" );
		char	a = 'a';
		char	b = 'b';

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min<char>( a, b ) = " << ::min<char>( a, b )
				  << std::endl;
	}
	{
		LOG( "test 9: test ::max() with int" );
		int	a = 42;
		int	b = 21;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "max<int>( a, b ) = " << ::max<int>( a, b ) << std::endl;
	}
	{
		LOG( "test 10: test ::max() with double" );
		double	a = 4.2;
		double	b = 2.1;

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "max<double>( a, b ) = " << ::max<double>( a, b ) << std::endl;
	}
	{
		LOG( "test 11: test ::max() with std::string" );
		std::string	a = "Hello";
		std::string	b = "World";

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "max<std::string>( a, b ) = " << ::max<std::string>( a, b )
				  << std::endl;
	}
	{
		LOG( "test 12: test ::max() with char" );
		char	a = 'a';
		char	b = 'b';

		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "max<char>( a, b ) = " << ::max<char>( a, b )
				  << std::endl;
	}
	{
		LOG( "test 13: test from subject's main" );
		int	a = 2;
		int	b = 3;

		::min( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string	c = "chaine1";
		std::string	d = "chaine2";

		::min( c, d );
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	return ( 0 );
}
