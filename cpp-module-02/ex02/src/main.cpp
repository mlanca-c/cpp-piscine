/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/23 16:55:35 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Debug.hpp"

int	main( int argc, char *argv[] ) {

	float	n1;
	int		n2;

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
	n1 = 4.224;
	n2 = 42;
	Fixed	a = Fixed( n1 );
	Fixed	b = Fixed( n2 );
	{
		LOG( "test 2: testing \'<\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " < " << b << ": "<< (a < b) << std::endl;
		std::cout << b << " < " << a << ": "<< (b < a) << std::endl;
		std::cout << a << " < " << a << ": "<< (a < a) << std::endl;
		std::cout << b << " < " << b << ": "<< (b < b) << std::endl;

	}
	{
		LOG( "test 3: testing \'>\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " > " << b << ": "<< (a > b) << std::endl;
		std::cout << b << " > " << a << ": "<< (b > a) << std::endl;
		std::cout << a << " > " << a << ": "<< (a > a) << std::endl;
		std::cout << b << " > " << b << ": "<< (b > b) << std::endl;

	}
	{
		LOG( "test 4: testing \'<=\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " <= " << b << ": "<< (a <= b) << std::endl;
		std::cout << b << " <= " << a << ": "<< (b <= a) << std::endl;
		std::cout << a << " <= " << a << ": "<< (a <= a) << std::endl;
		std::cout << b << " <= " << b << ": "<< (b <= b) << std::endl;

	}
	{
		LOG( "test 5: testing \'>=\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " >= " << b << ": "<< (a >= b) << std::endl;
		std::cout << b << " >= " << a << ": "<< (b >= a) << std::endl;
		std::cout << a << " >= " << a << ": "<< (a >= a) << std::endl;
		std::cout << b << " >= " << b << ": "<< (b >= b) << std::endl;

	}
	{
		LOG( "test 6: testing \'==\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " == " << b << ": "<< (a == b) << std::endl;
		std::cout << b << " == " << a << ": "<< (b == a) << std::endl;
		std::cout << a << " == " << a << ": "<< (a == a) << std::endl;
		std::cout << b << " == " << b << ": "<< (b == b) << std::endl;

	}
	{
		LOG( "test 7: testing \'!=\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " != " << b << ": "<< (a != b) << std::endl;
		std::cout << b << " != " << a << ": "<< (b != a) << std::endl;
		std::cout << a << " != " << a << ": "<< (a != a) << std::endl;
		std::cout << b << " != " << b << ": "<< (b != b) << std::endl;

	}
	{
		LOG( "test 8: testing \'+-\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << "-" << n1 << ": " << (-n1) << std::endl;

		std::cout << "+" << a << ": "<< (+a) << std::endl;
		std::cout << "+" << b << ": "<< (+b) << std::endl;
		std::cout << "-" << a << ": "<< (-a) << std::endl;
		std::cout << "-" << b << ": "<< (-b) << std::endl;

	}
	{
		LOG( "test 9: testing \'+\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " + " << b << " = "<< (a + b) << std::endl;
		std::cout << b << " + " << a << " = "<< (b + a) << std::endl;
		std::cout << a << " + " << a << " = "<< (a + a) << std::endl;
		std::cout << b << " + " << b << " = "<< (b + b) << std::endl;

	}
	{
		LOG( "test 10: testing \'-\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " - " << b << " = "<< (a - b) << std::endl;
		std::cout << b << " - " << a << " = "<< (b - a) << std::endl;
		std::cout << a << " - " << a << " = "<< (a - a) << std::endl;
		std::cout << b << " - " << b << " = "<< (b - b) << std::endl;

	}
	{
		LOG( "test 11: testing \'*\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " * " << b << " = "<< (a * b) << std::endl;
		std::cout << b << " * " << a << " = "<< (b * a) << std::endl;
		std::cout << a << " * " << a << " = "<< (a * a) << std::endl;
		std::cout << b << " * " << b << " = "<< (b * b) << std::endl;

	}
	{
		LOG( "test 12: testing \'/\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << " / " << b << " = "<< (a / b) << std::endl;
		std::cout << b << " / " << a << " = "<< (b / a) << std::endl;
		std::cout << a << " / " << a << " = "<< (a / a) << std::endl;
		std::cout << b << " / " << b << " = "<< (b / b) << std::endl;

	}
	{
		LOG( "test 13: testing \'[++,--]x\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << "++" << a << " = " << (++a) << std::endl;
		std::cout << "++" << b << " = " << (++b) << std::endl;
		std::cout << "--" << a << " = " << (--a) << std::endl;
		std::cout << "--" << b << " = " << (--b) << std::endl;

	}
	{
		LOG( "test 14: testing \'x[++,--]\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << a << "++" << " = " << (a++) << " : " << a << std::endl;
		std::cout << b << "++" << " = " << (b++) << " : " << b << std::endl;
		std::cout << a << "--" << " = " << (a--) << " : " << a << std::endl;
		std::cout << b << "--" << " = " << (b--) << " : " << b << std::endl;

	}
	{
		LOG( "test 15: testing \'max/min\' operator " << n1 << " and " << n2 << " as example" );

		std::cout << "max(" << a << ", " << b << ") = " << Fixed::max( a, b ) << std::endl;
		std::cout << "min(" << b << ", " << a << ") = " << Fixed::min( b, a ) << std::endl;
		std::cout << "max(" << a << ", " << a << ") = " << Fixed::max( a, a ) << std::endl;
		std::cout << "min(" << b << ", " << b << ") = " << Fixed::min( b, b ) << std::endl;

	}
	return ( 0 );
}
