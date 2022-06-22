/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 16:57:37 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Debug.hpp"

int	main( int argc, char *argv[] ) {

	int		n;
	float	f;

	(void)argc;
	(void)argv;
	{
		LOG( "test 1: subject test " );
		Fixed a;
		Fixed const b( 10 );
		Fixed const c( 42.42f );
		Fixed const d( b );

		a = Fixed( 1234.4321f );
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	}
	if (argc != 3) {
		return ( 0 );
	}
	n = std::stoi( argv[1] );
	f = std::stof( argv[2] );
	{
		LOG( "test 2: user tests " << n << " and " << f << " as example" );
		Fixed	a = Fixed( n );
		Fixed	b = Fixed( f );

		std::cout << "a (int):   " << a.toInt() << std::endl;
		std::cout << "a (float): " << a.toFloat() << std::endl;
		std::cout << "a (raw):   " << a.getRawBits() << std::endl;
		std::cout << "b (int):   " << b.toInt() << std::endl;
		std::cout << "b (float): " << b.toFloat() << std::endl;
		std::cout << "b (raw):   " << b.getRawBits() << std::endl;

	}
	return ( 0 );
}
