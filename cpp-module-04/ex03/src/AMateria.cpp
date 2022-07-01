/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:36:56 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 16:22:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

// AMateria::AMateria( void ) : _type( const_cast<std::string&>( std::string( "materia" ))) {
// 	DEBUG( "<AMateria> default constructor called" );
// }

AMateria::~AMateria( void ) { DEBUG( "<AMateria> destructor called" ); }

AMateria::AMateria( AMateria const& src ) : _type( src._type ) {
	DEBUG( "<AMateria> copy constructor called" );
}

AMateria::AMateria( std::string const& type ) : _type( type ) {
	DEBUG( "<AMateria> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

AMateria&	AMateria::operator=( AMateria const& rhs ) {

	const_cast<std::string&>( this->_type ) = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, AMateria const& rhs ) {

	os << "<AMateria> " << rhs.getType() << ":";
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	AMateria::getType( void ) const { return ( this->_type ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	AMateria::use( ICharacter& target ) {
	std::cout << "* does nothing to " << target << " *" << std::endl;
}
