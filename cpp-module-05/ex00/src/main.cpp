/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:51:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 11:41:47 by mlancac          ###   ########.fr       */
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
		Bureaucrat	a( "a", 87 );
		Bureaucrat	b( a );
		Bureaucrat	c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

	}
	{
		LOG( "test 2: some further testing" );
		Bureaucrat	d( "Dan", 150 );
		Bureaucrat	c( "Cam", 0 );

		try { Bureaucrat	a( "Ana", 151 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { Bureaucrat	b( "Bob", -1 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { c.incrementGrade(); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { d.decrementGrade(); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		std::cout << c << std::endl;
		std::cout << d << std::endl;
	}

	return ( 0 );
}
