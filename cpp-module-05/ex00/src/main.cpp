/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:51:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/28 10:01:03 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Bureaucrat.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;

	{
		LOG( "test 1: testing class Bureaucrat" );
		Bureaucrat	a( "Bob", 87 );
		Bureaucrat	b( a );
		Bureaucrat	c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

	}
	{
		LOG( "test 2: some further testing" );

		try {
			Bureaucrat	a( "A", 151 );

			a.incrementGrade();
			std::cout << a << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Bureaucrat	b( "B", -1 );

			b.incrementGrade();
			std::cout << b << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Bureaucrat	c( "C", 0 );

			c.incrementGrade();
			std::cout << c << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Bureaucrat	d( "D", 150 );

			d.decrementGrade();
			std::cout << d << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try {
			Bureaucrat	e( "E", 10 );

			e.decrementGrade();
			std::cout << e << std::endl;
			e.incrementGrade();
			std::cout << e << std::endl;
		}
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		// Bureaucrat	f( "F", 180 );
		// std::cout << f << std::endl;
	}

	return ( 0 );
}
