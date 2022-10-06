/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:51:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/06 11:12:20 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( int argc, char *argv[] ) {

	( void )argc;
	( void )argv;
	{
		LOG( "test 1: testing Shrubbery Creation Form Class" );

		Form*		form = new ShrubberyCreationForm( "home" );
		Bureaucrat	a( "A", 137);
		Bureaucrat	b( "B", 145);
		Bureaucrat	c( "C", 146);
		std::cout << *form << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a.executeForm( *form );
		c.signForm( *form );
		b.signForm( *form );
		a.signForm( *form );
		c.executeForm( *form );
		b.executeForm( *form );
		a.executeForm( *form );

		delete form;
	}
	{
		LOG( "test 2: testing Robotomy Request Form Class" );

		Form*		form = new RobotomyRequestForm( "average citizen" );
		Bureaucrat	a( "A", 45);
		Bureaucrat	b( "B", 72);
		Bureaucrat	c( "C", 73);
		std::cout << *form << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a.executeForm( *form );
		c.signForm( *form );
		b.signForm( *form );
		a.signForm( *form );
		c.executeForm( *form );
		b.executeForm( *form );
		a.executeForm( *form );

		delete form;
	}
	{
		LOG( "test 3: testing Presidential Pardon Form Class" );

		Form*		form = new PresidentialPardonForm( "average criminal" );
		Bureaucrat	a( "A", 5);
		Bureaucrat	b( "B", 25);
		Bureaucrat	c( "C", 26);
		std::cout << *form << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

		a.executeForm( *form );
		c.signForm( *form );
		b.signForm( *form );
		a.signForm( *form );
		c.executeForm( *form );
		b.executeForm( *form );
		a.executeForm( *form );

		delete form;
	}
	return ( 0 );
}
