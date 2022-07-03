/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:49:43 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 20:26:22 by mlancac          ###   ########.fr       */
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

Cure::Cure( Cure const& src ) : AMateria( src._type ) {
	DEBUG( "<Cure> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Cure&	Cure::operator=( Cure const& rhs ) {

	const_cast<std::string&>( this->_type ) = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Cure const& rhs ) {

	os << "<AMateria> " << rhs.getType();
	return ( os );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

Cure*	Cure::clone( void ) const { return ( new Cure( *this ) ); }

void	Cure::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
