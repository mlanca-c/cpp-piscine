/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:51:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/22 14:27:59 by mlancac          ###   ########.fr       */
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
	{
		LOG( "test 3: testing class Form" );
		Form	a( "a", false, 10, 5 );
		Form	b( a );
		Form	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;
	}
	{
		LOG( "test 4: some further testing" );
		Bureaucrat	b( "Ben", 10 );
		Form		f1( "Very Important Form", false, 1, 0 );
		Form		f2( "Not so Important Form", false, 20, 10 );

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

		try { Form	a( "a", false, 151, 0 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { Form	a( "a", false, -1, 0 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { Form	a( "a", false, 150, 160 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { Form	a( "a", false, 150, -1 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { b.signForm( f1 );; }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		b.signForm( f2 );

		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;

	}

	return ( 0 );
}
