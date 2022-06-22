/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:01:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/22 14:21:31 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Debug.hpp"

int	main( int argc, char *argv[] ) {

	(void)argc;
	(void)argv;
	{
		LOG("test 1: subject test");
		Fixed	a;
		Fixed	b( a );
		Fixed	c;

		c = b;

		std::cout << "a: " << a.getRawBits() << std::endl;
		std::cout << "b: " << b.getRawBits() << std::endl;
		std::cout << "c: " << c.getRawBits() << std::endl;
	}
	{
		LOG("test 2: testing a few more stuff");

		Fixed	a;
		Fixed	b( a );
		Fixed	c;

		a.setRawBits( 42 );
		std::cout << "a: " << a.getRawBits() << std::endl;
		std::cout << "b: " << b.getRawBits() << std::endl;
		std::cout << "c: " << c.getRawBits() << std::endl;

		b = a;
		c.setRawBits( 21 );
		std::cout << "a: " << a.getRawBits() << std::endl;
		std::cout << "b: " << b.getRawBits() << std::endl;
		std::cout << "c: " << c.getRawBits() << std::endl;

	}
	return ( 0 );
}
