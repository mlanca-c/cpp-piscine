/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:06:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 19:14:25 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

AMateria::AMateria( void ) : _type( "none" ) {
	DEBUG( "<AMateria> default constructor called" );
}

AMateria::~AMateria( void ) { DEBUG( "<AMateria> destructor called" ); }

AMateria::AMateria( AMateria const& src ) : _type( src._type ) {
	DEBUG( "<AMateria> copy constructor called" );
}

AMateria::AMateria( std::string const& type ) : _type( type ) {
	DEBUG( "<" << this->_type << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

AMateria&	AMateria::operator=( AMateria const& rhs ) {

	( void )rhs;
	// const_cast<std::string&>( this->_type ) = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, AMateria const& rhs ) {

	os << "<AMateria> " << rhs.getType();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	AMateria::getType( void ) const { return ( this->_type ); }

void	AMateria::use( ICharacter& target ) { ( void )target; }
