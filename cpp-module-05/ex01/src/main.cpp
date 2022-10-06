/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:51:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/28 10:43:24 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: testing Form Class" );
		Form	a( "A", 10, 5 );
		Form	b( a );
		Form	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

	}
	{
		LOG( "test 2: some further testing" );

		try {
			Form	a( "A", 151, 149 );
			std::cout << a << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Form	b( "B", 149, 151 );
			std::cout << b << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Form	c( "C", 0, 1 );
			std::cout << c << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Form	d( "D", 1, 0 );
			std::cout << d << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Form	e( "E", 2, 1 );
			std::cout << e << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		// Form	f( "F", 180, 1 );
		// std::cout << f << std::endl;
	}
	{
		LOG( "test 3: testing Form Class beSigned" );
		try {
			Bureaucrat	a( "A", 1 );
			std::cout << a << std::endl;

			Form	c( "C", 2, 1 );
			Form	d( "D", 90, 150 );

			std::cout << c << std::endl;
			std::cout << d << std::endl;

			c.beSigned( a );
			d.beSigned( a );

			c.beSigned( a );
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
	}
	{
		LOG( "test 4: testing Bureaucrat Class signForm" );
		try {
			Bureaucrat	a( "A", 80 );
			std::cout << a << std::endl;

			Form	c( "C", 2, 1 );
			Form	d( "D", 90, 150 );

			std::cout << c << std::endl;
			std::cout << d << std::endl;

			a.signForm( c );
			a.signForm( d );
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
	}

	return ( 0 );
}
