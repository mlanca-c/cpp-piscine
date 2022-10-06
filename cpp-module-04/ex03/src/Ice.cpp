/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:47:57 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:56:20 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Ice::Ice( void ) : AMateria( "ice" ) {
	DEBUG( "<Ice> default constructor called" );
}

Ice::~Ice( void ) { DEBUG( "<Ice> destructor called" ); }

Ice::Ice( Ice const& src ) {

	*this = src;
	DEBUG( "<Ice> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Ice&	Ice::operator=( Ice const& rhs ) {

	AMateria::operator=( rhs );
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Ice const& rhs ) {

	os << "Materia <" << rhs.getType() << ">";
	return ( os );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

Ice*	Ice::clone( void ) const { return ( new Ice( *this )); }

void	Ice::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}
