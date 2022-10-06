/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 12:07:18 by mlanca-c         ###   ########.fr       */
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

	LOG( "Running a bunch of tests" );
	Point const a( 0.0f, 0.0f );
	Point const b( 10.0f, 0.0f );
	Point const c( 0.0f, 10.0f );

	Point const p1(0.5f, 0.5f);
	Point const p2(0.1f, 0.2f);
	Point const p3(-0.1f, 0.2f);
	Point const p4(0.1f, -0.2f);
	Point const p5(-0.1f, -0.2f);
	Point const p6(0.1f, 0.23f);

	std::cout << "bsp:" << std::endl;
	std::cout << "      a" << a << std::endl;
	std::cout << "      b" << b << std::endl;
	std::cout << "      c" << c << std::endl;

	std::cout << "  point" << p1 << " ";
	std::cout << "belongs inside triangle: ";
	std::cout << ( bsp( a, b, c, p1 ) == true ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "  point" << p2 << " ";
	std::cout << "belongs inside triangle: ";
	std::cout << ( bsp( a, b, c, p2 ) == true ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "  point" << p3 << " ";
	std::cout << "belongs inside triangle: ";
	std::cout << ( bsp( a, b, c, p3 ) == true ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "  point" << p4 << " ";
	std::cout << "belongs inside triangle: ";
	std::cout << ( bsp( a, b, c, p4 ) == true ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "  point" << p5 << " ";
	std::cout << "belongs inside triangle: ";
	std::cout << ( bsp( a, b, c, p5 ) == true ? "true" : "false" );
	std::cout << std::endl;
	std::cout << "  point" << p6 << " ";
	std::cout << "belongs inside triangle: ";
	std::cout << ( bsp( a, b, c, p6 ) == true ? "true" : "false" );
	std::cout << std::endl;

	return (0);
}
