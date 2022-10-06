/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:51:12 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/06 11:23:58 by mlanca-c         ###   ########.fr       */
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
		LOG( "test 1: testing Intern class" );
		Intern	a;
		Intern	b( a );
		Intern	c;

		c = b;

		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		std::cout << "c: " << c << std::endl;

	}
	{
		LOG( "test 2: testing Intern Class with user's input" );
		Intern		i;
		Bureaucrat	a( "A", 5 );
		Form*		tmp;

		std::cout << "Intern <" << i << ">" << std::endl;
		std::cout << "Bureaucrat <" << a << ">" << std::endl;
		if ( argc == 3 )
			try { tmp = i.makeForm( argv[1], argv[2] ); }
			catch ( std::exception& e ) {
				std::cerr << e.what() << std::endl;
				return ( 1 );
			}
		else {
 			try { tmp = i.makeForm( "PresidentialPardonForm", "average criminal" ); }
			catch ( std::exception& e ) {
				std::cerr << e.what() << std::endl;
				return ( 1 );
			}
		}

		a.signForm( *tmp );
		a.executeForm( *tmp );

		delete tmp;
	}

	return ( 0 );
}
