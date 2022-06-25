/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/25 14:27:58 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"
#include "Debug.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main( int argc, char *argv[] ) {

	(void)argc;
	(void)argv;
	{
		LOG( "test 1: test Point class" );
		Point	a( 40, 10 );
		Point	b( 20, 30 );
		Point	c;

		c = b;

		std::cout << "a" << a << std::endl;
		std::cout << "b" << b << std::endl;
		std::cout << "c" << c << std::endl;

		std::cout << "a + b = " << ( a + b ) << std::endl;
		std::cout << "b + c = " << ( b + c ) << std::endl;
		std::cout << "a + c = " << ( a + c ) << std::endl;

		std::cout << "a - b = " << ( a - b ) << std::endl;
		std::cout << "b - c = " << ( b - c ) << std::endl;
		std::cout << "a - c = " << ( a - c ) << std::endl;

		std::cout << "a * b = " << ( a * b ) << std::endl;
		std::cout << "b * c = " << ( b * c ) << std::endl;
		std::cout << "a * c = " << ( a * c ) << std::endl;

	}
	{
		LOG( "test 2: test if sqare belongs to triangle" );
		Point	a, b, c, point;

		a = Point( 0.0f, 0.0f );
		b = Point( 10.0f, 0.0f );
		c = Point( 0.0f, 10.0f );
		point = Point( 1.0f, 10.0f );

		std::cout << "belongs inside triangle: ";
		std::cout << ( bsp( a, b, c, point ) == true ? "true" : "false" );
		std::cout << std::endl;
	}
	{
		LOG( "test 3: user input testing" );
		float	ax, ay;
		Point	a;

		std::cout << "ax: ";
		std::cin >> ax;
		std::cout << "ay: ";
		std::cin >> ay;
		a = Point( ax, ay );
		std::cout << "a" << a << std::endl;

		float	bx, by;
		Point	b;

		std::cout << "bx: ";
		std::cin >> bx;
		std::cout << "by: ";
		std::cin >> by;
		b = Point( bx, by );
		std::cout << "b" << b << std::endl;

		float	cx, cy;
		Point	c;

		std::cout << "cx: ";
		std::cin >> cx;
		std::cout << "cy: ";
		std::cin >> cy;
		c = Point( cx, cy );
		std::cout << "c" << c << std::endl;

		float	px, py;
		Point	point;

		std::cout << "px: ";
		std::cin >> px;
		std::cout << "py: ";
		std::cin >> py;
		point = Point( px, py );
		std::cout << "p" << point << std::endl;


		std::cout << "bsp:" << std::endl;
		std::cout << "      a" << a << std::endl;
		std::cout << "      b" << b << std::endl;
		std::cout << "      c" << c << std::endl;
		std::cout << "  point" << point << std::endl;

		std::cout << "belongs inside triangle: ";
		std::cout << ( bsp( a, b, c, point ) == true ? "true" : "false" );
		std::cout << std::endl;
	}
	return (0);
}
