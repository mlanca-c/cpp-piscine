/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:51:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 15:23:31 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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
		// sign: 145; execute: 137
		LOG( "test 3: testing Shrubbery Creation Form Class" );

		Form	*s1 = new ShrubberyCreationForm( "home" );
		Form	*s2 = new ShrubberyCreationForm( "office" );
		Form	*s3 = new ShrubberyCreationForm( "school" );
		Bureaucrat	a( "Ana", 137);
		Bureaucrat	b( "Ben", 145);
		Bureaucrat	c( "Cam", 150);

		a.signForm( *s1 );
		a.executeForm( *s1 );
		
		b.signForm( *s2 );
		try { b.executeForm( *s2 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
		
		try { c.signForm( *s3 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { c.executeForm( *s3 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		delete s1;
		delete s2;
		delete s3;
	}
	{
		// sign: 72; execute: 45
		LOG( "test 4: testing Robotomy Request Form Class" );

		Bureaucrat	a( "Ana", 45);
		Form		*s1 = new RobotomyRequestForm( "Ben" );

		a.signForm( *s1 );
		a.executeForm( *s1 );
		
		Form		*s2 = new RobotomyRequestForm( "Cam" );

		Bureaucrat	b( "Ben", 72);
		b.signForm( *s2 );
		try { b.executeForm( *s2 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
		
		Bureaucrat	c( "Cam", 73);
		Form		*s3 = new RobotomyRequestForm( "Ana" );

		try { c.signForm( *s3 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
		try { c.executeForm( *s3 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		delete s1;
		delete s2;
		delete s3;
	}
	{
		// sign: 25; execute: 5
		LOG( "test 5: testing Presidential Pardon Form Class" );

		Form	*s1 = new PresidentialPardonForm( "Ben" );
		Form	*s3 = new PresidentialPardonForm( "Cam" );
		Form	*s2 = new PresidentialPardonForm( "Ana" );
		Bureaucrat	a( "Ana", 5);
		Bureaucrat	b( "Ben", 25);
		Bureaucrat	c( "Cam", 26);

		a.signForm( *s1 );
		a.executeForm( *s1 );
		
		b.signForm( *s2 );
		try { b.executeForm( *s2 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
		
		try { c.signForm( *s3 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		try { c.executeForm( *s3 ); }
		catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

		delete s1;
		delete s2;
		delete s3;
	}
	{
		LOG( "test 6: testing Intern Class" );
		Intern		i;
		Bureaucrat	a( "Ana", 5 );
		Form*		tmp;

		if ( argc == 3 )
			try { tmp = i.makeForm( argv[1], argv[2] ); }
			catch ( std::exception& e ) {
				std::cerr << e.what() << std::endl;
				return ( 1 );
			}
		else
 			tmp = i.makeForm( "ShrubberyCreationForm", "house" );

		a.signForm( *tmp );
		a.executeForm( *tmp );

		delete tmp;
	}

	return ( 0 );
}
