/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:01:19 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/04 14:47:14 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form( "RobotomyRequestForm", "none", false, 72, 45 ) {
	DEBUG( "<RobotomyRequestForm> default constructor called" );
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	DEBUG( "<RobotomyRequestForm> destructor called" );
}

RobotomyRequestForm::
	RobotomyRequestForm( RobotomyRequestForm const& src ) : Form( src ) {
	DEBUG( "<RobotomyRequestForm> copy constructor called" );
}

RobotomyRequestForm::RobotomyRequestForm( std::string const& target )
	: Form( "RobotomyRequestForm", target, false, 72, 45 ) {
	DEBUG( "<RobotomyRequestForm> " << this->getName() << " constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

RobotomyRequestForm&	RobotomyRequestForm	
	::operator=( RobotomyRequestForm const& rhs ) {

	Form::operator=( rhs );
	return ( *this );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	RobotomyRequestForm::execute( Bureaucrat const& b ) const {

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

	std::cout << "<Form> " << this->getName() << " makes some drilling noises.";
	std::cout << " Then, informes " << this->getTarget();
	std::cout << " has been robotomized successfully 50% of the time" << std::endl;
}
