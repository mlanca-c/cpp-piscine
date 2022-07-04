/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:38:31 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 13:21:48 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Bureaucrat::Bureaucrat( void ) : _name( "bureaucrat" ), _grade( 150 ) {
	DEBUG( "<Bureaucrat> default constructor called" );
}

Bureaucrat::~Bureaucrat( void ) { DEBUG( "<Bureaucrat> destructor called" ); }

Bureaucrat::Bureaucrat( Bureaucrat const& src ) {

	*this = src;
	DEBUG( "<Bureaucrat> copy constructor called" );
}

Bureaucrat::
	Bureaucrat( std::string const& name, int grade ) throw( std::exception )
	: _name( name ) {

	if ( grade > 150 )
		throw( Bureaucrat::GradeTooHighException() );
	if ( grade < 0 )
		throw( Bureaucrat::GradeTooLowException() );
	else
		this->_grade = grade;
	DEBUG( "<Bureaucrat> " << this->_name << " constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Bureaucrat&	Bureaucrat::operator=( Bureaucrat const& rhs ) {

	const_cast<std::string&>( this->_name ) = rhs._name;
	this->_grade = rhs._grade;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Bureaucrat const& rhs ) {

	os << "<Bureaucrat> " << rhs.getName() << ", bureaucrat grade ";
	os << rhs.getGrade();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	Bureaucrat::getName( void ) const {
	return ( this->_name );
}

int	Bureaucrat::getGrade( void ) const { return ( this->_grade ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Bureaucrat::incrementGrade( void ) throw( std::exception ) {

	if ( this->_grade - 1 < 0 )
		throw( Bureaucrat::GradeTooLowException() );
	this->_grade--;
}

void	Bureaucrat::decrementGrade( void ) throw( std::exception ) {

	if ( this->_grade + 1 > 150 )
		throw( Bureaucrat::GradeTooHighException() );
	this->_grade++;
}

void	Bureaucrat::signForm( Form& form ) {

	try { form.beSigned( *this ); }
	catch ( std::exception& e ) {

		std::cout << "<Bureaucrat> " << this->_name << " couldn't sign ";
		std::cout << form.getName() << " because " << e.what() << std::endl;

		return ;
	}

	std::cout << "<Bureaucrat> " << this->_name << " signed " << form.getName();
	std::cout << std::endl;
}
/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

char const*	Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ( "Bureaucrat: Exception: grade too high" );
}

char const*	Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ( "Bureaucrat: Exception: grade too low" );
}
