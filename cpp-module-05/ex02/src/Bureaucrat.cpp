/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 10:38:31 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/28 11:06:27 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Bureaucrat::Bureaucrat( void ) : _name( "bureaucrat" ), _grade( 150 ) {
	DEBUG( "Bureaucrat <" << this->_name << "> default constructor called" );
}

Bureaucrat::~Bureaucrat( void ) {
	DEBUG( "Bureaucrat <" << this->_name << "> destructor called" );
}

Bureaucrat::Bureaucrat( Bureaucrat const& src ) {

	*this = src;
	DEBUG( "Bureaucrat <" << this->_name << "> copy constructor called" );
}

Bureaucrat::
	Bureaucrat( std::string const& name, int grade ) throw( std::exception )
	: _name( name ) {

	if ( grade > 150 )
		throw( Bureaucrat::GradeTooLowException() );
	if ( grade < 1 )
		throw( Bureaucrat::GradeTooHighException() );
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

void	Bureaucrat::setGrade( int grade ) { this->_grade = grade; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Bureaucrat::incrementGrade( void ) throw( std::exception ) {

	if ( this->_grade - 1 < 1 )
		throw( Bureaucrat::GradeTooLowException() );
	this->_grade--;
}

void	Bureaucrat::decrementGrade( void ) throw( std::exception ) {

	if ( this->_grade + 1 > 150 )
		throw( Bureaucrat::GradeTooHighException() );
	this->_grade++;
}

void	Bureaucrat::signForm( Form& form ) {

	try {

		form.beSigned( *this );
		std::cout << "<Bureaucrat> " << this->_name << " signed "
				  << form.getName() << std::endl;
	}
	catch ( std::exception& e ) {

		std::cout << "<Bureaucrat> " << this->_name << " couldn't sign "
				  << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( Form const& form ) {

	try {
		form.execute( *this );
		std::cout << "<Bureaucrat> " << this->_name << " executed "
				  << form.getName() << std::endl;
	}
	catch ( std::exception& e ) {
		std::cout << "<Bureaucrat> " << this->_name << " couldn't execute "
				  << form.getName() << " because " << e.what() << std::endl;
	}
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
