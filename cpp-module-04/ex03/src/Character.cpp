/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:12:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/07/03 20:54:13 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Character::Character( void ) : _name( "default" ) {
	for ( int i = 0; i < 4; i++ )
		this->_inventory[i] = NULL;
	DEBUG( "<Character> default constructor called" );
}

Character::~Character( void ) {

	for ( int i = 0; i < 4; i++ )
		if ( this->_inventory[i] )
			delete this->_inventory[i];
	DEBUG( "<Character> destructor called" );
}

Character::Character( Character const& src ) {

	*this = src;
	DEBUG( "<Character> copy constructor called" );
}

Character::Character( std::string const& name ) : _name( name ) {
	DEBUG( "<" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Character&	Character::operator=( Character const& rhs ) {

	const_cast<std::string&>( this->_name ) = rhs._name;
	for ( int i = 0; i < 4; i++ )
		this->_inventory[i] = rhs._inventory[i];

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Character const& rhs ) {

	os << "<Character> " << rhs.getName();
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	Character::getName( void ) const { return ( this->_name ); }

AMateria*	Character::getInventory( int idx ) const {
	return ( this->_inventory[idx] );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Character::equip( AMateria* m ) {

	if ( !m )
		return ;

	for ( int i = 0; i < 4; i++ ) {

		if ( !( this->_inventory[i] )) {
			this->_inventory[i] = m;
			DEBUG( "<" << this->_name << "> equiped " << *m );
			return ;
		}
	}
}

void	Character::unequip( int idx ) {

	if ( idx >= 0 && idx <= 4 && this->_inventory[idx] )
		this->_inventory[idx] = NULL;
	else
		return ;

	DEBUG( "<" << this->_name << "> unequiped "
	   	<< this->_inventory[idx]->getType());
}

void	Character::use( int idx, ICharacter& target ) {

	if ( idx >= 0 && idx <= 4 )
		this->_inventory[idx]->use( target );
}
