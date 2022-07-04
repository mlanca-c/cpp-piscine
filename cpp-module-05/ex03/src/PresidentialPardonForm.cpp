/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:06:25 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 14:49:30 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

PresidentialPardonForm::PresidentialPardonForm( void )
	: Form( "PresidentialPardonForm", "none", false, 25, 5 ) {
	DEBUG( "<PresidentialPardonForm> default constructor called" );
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	DEBUG( "<PresidentialPardonForm> destructor called" );
}

PresidentialPardonForm::
	PresidentialPardonForm( PresidentialPardonForm const& src ) : Form( src ) {
	DEBUG( "<PresidentialPardonForm> copy constructor called" );
}

PresidentialPardonForm::PresidentialPardonForm( std::string const& target )
	: Form( "PresidentialPardonForm", target, false, 25, 5 ) {
	DEBUG( "<PresidentialPardonForm> " << this->getName() << " constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

PresidentialPardonForm&	PresidentialPardonForm	
	::operator=( PresidentialPardonForm const& rhs ) {

	Form::operator=( rhs );
	return ( *this );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	PresidentialPardonForm::execute( Bureaucrat const& b ) const {

	if ( this->getIsSigned() == false ) {
		std::cout << "<Form> " << this->getName() << " failed because: ";
		throw( Form::FormNotSignedException() );
		return ;
	}

	if ( b.getGrade() > this->getExecuteGrade() ) {
		std::cout << "<Form> " << this->getName() << " failed because: ";
		throw( Form::GradeTooLowException() );
		return ;
	}

	std::cout << "<Form> " << this->getName() << " informs that ";
	std::cout << this->getTarget();
	std::cout << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
