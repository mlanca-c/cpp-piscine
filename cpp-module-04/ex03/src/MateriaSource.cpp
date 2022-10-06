/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:43:24 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 20:47:30 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

MateriaSource::MateriaSource( void ) {

	for ( int i = 0; i < 4; i++ )
		this->_inventory[i] = NULL;
	DEBUG( "<MateriaSource> default constructor called" );
}

MateriaSource::~MateriaSource( void ) {

	for ( int i = 0; i < 4; i++ )
		if ( this->_inventory[i] )
			delete this->_inventory[i];

	DEBUG( "<MateriaSource> destructor called" );
}

MateriaSource::MateriaSource( MateriaSource const& src ) {

	*this = src;
	DEBUG( "<MateriaSource> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

MateriaSource&	MateriaSource::operator=( MateriaSource const& rhs ) {

	for ( int i = 0; i < 4; i++ )
		if ( this->_inventory[i] )
			delete this->_inventory[i];

	for ( int i = 0; i < 4; i++ )
		this->_inventory[i] = rhs._inventory[i];

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, MateriaSource const& rhs ) {

	( void )rhs;
	os << "<MateriaSource>";
	for ( int i = 0; i < 4; i++ )
		if ( rhs.getInventory( i ) )
			os << rhs.getInventory( i )->getType()
				<< ( rhs.getInventory( i + 1 ) ? ", " : "" );
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

AMateria*	MateriaSource::getInventory( int idx ) const {
	return ( this->_inventory[idx] );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	MateriaSource::learnMateria( AMateria* m ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( !( this->_inventory[i] )) {
			this->_inventory[i] = m;
			DEBUG( "<MateriaSource> learned " << m->getType() );
			return ;
		}
	}
	DEBUG( "<MateriaSource> has no more inventory space left" );
}

AMateria*	MateriaSource::createMateria( std::string const& type ) {

	for ( int i = 0; ( i < 4 && this->_inventory[i] ); i++ ) {

		if ( !( this->_inventory[i]->getType().compare( type ))) {
			DEBUG( "<MateriaSource> created "
		 		<< this->_inventory[i]->getType() );

			return ( this->_inventory[i]->clone() );
		}
	}

	return ( NULL );
}
