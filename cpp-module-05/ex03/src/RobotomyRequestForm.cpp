/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:01:19 by mlancac           #+#    #+#             */
/*   Updated: 2022/10/06 11:10:32 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm( void )
	: Form( "RobotomyRequestForm", "none", 72, 45 ) {
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
	: Form( "RobotomyRequestForm", target, 72, 45 ) {
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

void	RobotomyRequestForm::_execute( void ) const {

	srand( time(NULL) );
	int	i = rand() % 2;

	std::cout << "<Form> " << this->getName() << ": * drilling noise * ";
	std::cout << this->getTarget() << " ";
	if ( i == 1 )
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << " has not been robotomized successfully" << std::endl;
}
