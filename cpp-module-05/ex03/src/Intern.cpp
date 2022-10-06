/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:53:19 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/06 11:36:11 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Intern::Intern( void ) {

	this->_formTemplate[0] = &Intern::cloneShrubberyCreationForm;
	this->_formTemplate[1] = &Intern::cloneRobotomyRequestForm;
	this->_formTemplate[2] = &Intern::clonePresidentialPardonForm;
	this->_form[0] = "ShrubberyCreationForm";
	this->_form[1] = "RobotomyRequestForm";
	this->_form[2] = "PresidentialPardonForm";

	DEBUG( "<Intern> default constructor called" );
}

Intern::~Intern( void ) { DEBUG( "<Intern> destructor called" ); }

Intern::Intern( Intern const& src ) {
	*this = src;
	DEBUG( "<Intern> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Intern&	Intern::operator=( Intern const& rhs ) {

	( void )rhs;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Intern const& rhs ) {

	( void )rhs;
	os << "intern";
	return ( os );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

Form*	Intern::makeForm( std::string const& name,
		std::string const& target ) const throw( std::exception ) {

	int	i;
	for (i = 0; i < 3; i++)
		if ( this->_form[i] == name )
			break ;
	if ( i == 3)
		throw( Intern::NoSuchFormException() );
	return (( this->*_formTemplate[i] )( target ));
}

Form*	Intern::cloneShrubberyCreationForm( std::string const& target ) const {
	return ( new ShrubberyCreationForm( target ));
}

Form*	Intern::cloneRobotomyRequestForm( std::string const& target ) const {
	return ( new RobotomyRequestForm( target ));
}

Form*	Intern::clonePresidentialPardonForm( std::string const& target ) const {
	return ( new PresidentialPardonForm( target ));
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

char const*	Intern::NoSuchFormException::what( void ) const throw() {
	return ( "Intern: Exception: no such form" );
}
