/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:01:22 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/07/01 16:18:01 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Character::Character( void ) {
	DEBUG( "<Character> default constructor called" );
}

Character::~Character( void ) { DEBUG( "<Character> destructor called" ); }

Character::Character( Character const& src )
	: _name( src._name ), _inventory( src._inventory ) {
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
	this->_inventory = rhs._inventory;
	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, ICharacter const& rhs ) {

	os << "<Character> " << rhs.getName() << ":";
	return ( os );
}

std::ostream&	operator<<( std::ostream& os, Character const& rhs ) {

	os << "<Character> " << rhs.getName() << ":";
	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	Character::getName( void ) const { return ( this->_name ); }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Character::equip( AMateria* m ) {

	for ( int i = 0; i < 4; i++ )
		if ( !this->_inventory[i] ) this->_inventory[i] = m;

	DEBUG( "<" << this->_name << "> equiped " << m );
}

void	Character::unequip( int idx ) {

	this->_inventory[i] = NULL;
	DEBUG( "<" << this->_name << "> unequiped " << this->_inventory[idx] );
}

void	Character::use( int idx, ICharacter &target ) {
	this->_inventory[idx].use(target);
}
