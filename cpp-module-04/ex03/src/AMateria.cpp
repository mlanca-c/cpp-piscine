/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 22:06:04 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 09:50:42 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

AMateria::AMateria( void ) : _type( "none" ) {
	DEBUG( "Materia <" << this->_type << "> default constructor called" );
}

AMateria::~AMateria( void ) { 
	DEBUG( "Materia <" << this->_type << "> destructor called" );
}

AMateria::AMateria( AMateria const& src ) {

	*this = src;
	DEBUG( "Materia <" << this->_type << "> copy constructor called" );
}

AMateria::AMateria( std::string const& type ) : _type( type ) {
	DEBUG( "Materia <" << this->_type << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

AMateria&	AMateria::operator=( AMateria const& rhs ) {

	const_cast<std::string&>( this->_type ) = rhs._type;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, AMateria const& rhs ) {

	os << "Materia <" << rhs.getType() << ">";
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	AMateria::getType( void ) const { return ( this->_type ); }

void	AMateria::use( ICharacter& target ) {
	std::cout << "* uses materia at " << target.getName() << " *" << std::endl;
}
