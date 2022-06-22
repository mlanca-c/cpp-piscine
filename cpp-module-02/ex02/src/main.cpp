/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 17:28:28 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Debug.hpp"

int	main( int argc, char *argv[] ) {

	int		n1;
	float	n2;

	(void)argc;
	(void)argv;
	{
		LOG( "test 1: subject test " );
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	if (argc != 3) {
		return ( 0 );
	}
	n1 = std::stof( argv[1] );
	n2 = std::stof( argv[2] );
	{
		LOG( "test 2: testing \'<\' operator " << n1 << " and " << n2 << " as example" );
		Fixed	a = Fixed( n1 );
		Fixed	b = Fixed( n2 );

		std::cout << a << " < " << b << (a < b) << std::endl;
		std::cout << b << " < " << a << (b < a) << std::endl;
		std::cout << a << " < " << a << (a < a) << std::endl;
		std::cout << b << " < " << b << (b < b) << std::endl;

	}
	return ( 0 );
}
