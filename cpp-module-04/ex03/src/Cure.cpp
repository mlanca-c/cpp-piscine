/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:52:02 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 16:12:05 by mlanca-c         ###   ########.fr       */
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

Cure::Cure( Cure const& src ) : AMateria( src ) {
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
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

AMateria*	AMateria::clone( void ) { return ( new Cure( *this ) ); }

void	AMateria::use( ICharacter& target ) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
