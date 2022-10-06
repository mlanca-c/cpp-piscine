/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:49:43 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:59:51 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Cure::Cure( void ) : AMateria( "cure" ) {
	DEBUG( "<Cure> default constructor called" );
}

Cure::~Cure( void ) { DEBUG( "<Cure> destructor called" ); }

Cure::Cure( Cure const& src ) {

	*this = src;
	DEBUG( "<Cure> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Cure&	Cure::operator=( Cure const& rhs ) {

	AMateria::operator=( rhs );
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Cure const& rhs ) {

	os << "Materia <" << rhs.getType() << ">";
	return ( os );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

Cure*	Cure::clone( void ) const { return ( new Cure( *this ) ); }

void	Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
