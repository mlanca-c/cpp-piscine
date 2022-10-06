/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:43:24 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 10:53:25 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

MateriaSource::MateriaSource( void ) : _amount( 0 ) {
	DEBUG( "<MateriaSource> default constructor called" );
}

MateriaSource::~MateriaSource( void ) {

	for ( int i = 0; i < this->_amount; i++ ) delete this->_inventory[i];
	DEBUG( "<MateriaSource> destructor called" );
}

MateriaSource::MateriaSource( MateriaSource const& src ) : _amount( 0 ) {

	*this = src;
	DEBUG( "<MateriaSource> copy constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

MateriaSource&	MateriaSource::operator=( MateriaSource const& rhs ) {

	for ( int i = 0; i < this->_amount; i++ )
		delete this->_inventory[i];

	this->_amount = rhs._amount;
	for ( int i = 0; i < this->_amount; i++ )
		this->_inventory[i] = rhs._inventory[i]->clone();

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, MateriaSource const& rhs ) {

	os << "<MateriaSource> ";
	for ( int i = 0; i < rhs.getAmount(); i++ ) {
		os << rhs.getInventory( i )->getType() << ":" << rhs.getInventory( i )
		   << ( i < rhs.getAmount() ? ", " : "" );
	}

	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

AMateria*	MateriaSource::getInventory( int idx ) const {
	return ( this->_inventory[idx] );
}

int	MateriaSource::getAmount( void ) const { return ( this->_amount ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	MateriaSource::learnMateria( AMateria* m ) {

	if ( !m ) std::cout << "<MateriaSource> cannot learn from nullptr";
	else if ( this->_amount == 4 )
		std::cout << "<MateriaSource> has no more inventory space left";
	else {

		for ( int i = 0; i < this->_amount; i++ ) {

			if ( this->_inventory[i] == m ) {
				
				std::cout << "<MateriaSource> already learned " << m->getType()
						  << ":" << m << std::endl;

				return ;
			}
		}

		this->_inventory[ this->_amount ] = m;
		std::cout << "<MateriaSource> learned " << m->getType() << ":" << m;
		this->_amount++;
	}
	std::cout << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const& type ) {

	for ( int i = 0; ( i < this->_amount ); i++ ) {

		if ( this->_inventory[i]->getType() == type ) {

			std::cout << "<MateriaSource> created "
				      << this->_inventory[i]->getType()
			          << std::endl;
			return ( this->_inventory[i]->clone() );
		}
	}
	std::cout << "<MateriaSource> hasn't learned " << type << " yet"
		      << std::endl;
	return ( NULL );
}
