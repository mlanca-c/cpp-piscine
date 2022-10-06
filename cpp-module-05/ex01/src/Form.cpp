/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:53:22 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/28 10:40:48 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Form::Form( void )
	: _name( "Form" ), _isSigned( false ), _signedGrade( 150 ),
	_executeGrade( 150 ) {
	DEBUG( "<Form> default constructor called" );
}

Form::~Form( void ) { DEBUG( "<Form> destructor called" ); }

Form::Form( Form const& src )
	: _name( src._name ), _isSigned( src._isSigned ),
	_signedGrade( src._signedGrade ), _executeGrade( src._executeGrade ) {
	DEBUG( "<Form> copy constructor called" );
}

Form::Form( std::string const& name, int signedGrade,
	int executeGrade ) throw( std::exception )
	: _name( name ), _isSigned( false ), _signedGrade( signedGrade ),
	_executeGrade( executeGrade ) {

	if ( this->_signedGrade < 1 )
		throw( Bureaucrat::GradeTooLowException());
	if ( this->_signedGrade > 150 )
		throw( Bureaucrat::GradeTooHighException());
	if ( this->_executeGrade < 1 )
		throw( Bureaucrat::GradeTooLowException());
	if ( this->_executeGrade > 150 )
		throw( Bureaucrat::GradeTooHighException());
	DEBUG( "<Form> " << this->_name << "constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Form&	Form::operator=( Form const& rhs ) {

	const_cast<std::string&>( this->_name ) = rhs._name;
	this->_isSigned = rhs._isSigned;
	*const_cast<int*>(&( this->_signedGrade )) = rhs._signedGrade;
	*const_cast<int*>(&( this->_executeGrade )) = rhs._executeGrade;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Form const& rhs ) {

	os << "<Form> " << rhs.getName() << " signed: ";
	os << ( rhs.getIsSigned() ? "true; " : "false; " );
	os << "grade to sign: " << rhs.getSignedGrade() << "; ";
	os << "grade to execute: " << rhs.getExecuteGrade();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	Form::getName( void ) const { return ( this->_name ); }

bool	Form::getIsSigned( void ) const { return ( this->_isSigned ); }

int	Form::getSignedGrade( void ) const { return ( this->_signedGrade ); }

int	Form::getExecuteGrade( void ) const { return ( this->_executeGrade ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Form::beSigned( Bureaucrat& b ) throw( std::exception ) {
	if ( this->_isSigned )
		throw ( Form::FormAlreadySignedException() );
	if ( b.getGrade() >= this->_signedGrade )
		throw ( Bureaucrat::GradeTooLowException() );
	this->_isSigned = true;
}

/* ************************************************************************** */
/* Exceptions                                                                 */
/* ************************************************************************** */

char const*	Form::GradeTooHighException::what( void ) const throw() {
	return ( "Form: Exception: grade too high" );
}

char const*	Form::GradeTooLowException::what( void ) const throw() {
	return ( "Form: Exception: grade too low" );
}

char const*	Form::FormAlreadySignedException::what( void ) const throw() {
	return ( "Form: Exception: form was already signed" );
}
