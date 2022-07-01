/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:45:06 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 16:12:26 by mlanca-c         ###   ########.fr       */
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

Ice::Ice( Ice const& src ) AMateria( src ) {
	DEBUG( "<Ice> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Ice&	Ice::operator=( Ice const& rhs ) {
	
	const_cast<std::string&>( this->_type ) = rhs._type;
	return ( *this );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

AMateria*	AMateria::clone( void ) {
	return ( new Ice( *this ) );
}

void	AMateria::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << "*";
	std::cout << std::endl;
}
