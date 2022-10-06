/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:32:14 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 14:47:30 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: Form( "ShrubberyCreationForm", "none", false, 145, 137 ) {
	DEBUG( "<ShrubberyCreationForm> default constructor called" );
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	DEBUG( "<ShrubberyCreationForm> destructor called" );
}

ShrubberyCreationForm::
	ShrubberyCreationForm( ShrubberyCreationForm const& src ) : Form( src ) {
	DEBUG( "<ShrubberyCreationForm> copy constructor called" );
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const& target )
	: Form( "ShrubberyCreationForm", target, false, 145, 137 ) {
	DEBUG( "<ShrubberyCreationForm> " << this->getName() << " constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

ShrubberyCreationForm&	ShrubberyCreationForm
	::operator=( ShrubberyCreationForm const& rhs ) {

	Form::operator=( rhs );
	return ( *this );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	ShrubberyCreationForm::execute( Bureaucrat const& b ) const {

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

	std::cout << "<Form> " << this->getName() << ": created a file ";
	std::cout << this->getTarget() << "_shrubbery in the working directory, ";
	std::cout << "and wrote ASCII trees inside it" << std::endl;
}
