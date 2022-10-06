/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:47:57 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 20:50:22 by mlancac          ###   ########.fr       */
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

Ice::Ice( Ice const& src ) : AMateria( src._type ) {
	DEBUG( "<Ice> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Ice&	Ice::operator=( Ice const& rhs ) {

	const_cast<std::string&>( this->_type ) = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Ice const& rhs ) {

	os << "<AMateria> " << rhs.getType();
	return ( os );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

Ice*	Ice::clone( void ) const { return ( new Ice( *this )); }

void	Ice::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
	std::cout << std::endl;
}
