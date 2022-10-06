/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:12:49 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/27 11:13:23 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

Character::Character( void ) : _name( "default" ), _amount( 0 ) {
	DEBUG( "Character <" << this->_name << "> default constructor called" );
}

Character::~Character( void ) {

	for ( int i = 0; i < this->_amount; i++ ) delete this->_inventory[i];
	DEBUG( "Character <" << this->_name << "> destructor called" );
}

Character::Character( Character const& src ) : _amount( 0 ) {

	*this = src;
	DEBUG( "Character <" << this->_name << "> copy constructor called" );
}

Character::Character( std::string const& name ) : _name( name ), _amount( 0 ) {
	DEBUG( "Character <" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

Character&	Character::operator=( Character const& rhs ) {

	const_cast<std::string&>( this->_name ) = rhs._name;

	for ( int i = 0; i < this->_amount; i++ )
		delete this->_inventory[i];

	for ( int i = 0; i < this->_amount; i++ )
		this->_inventory[i] = rhs._inventory[i]->clone();

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, Character const& rhs ) {

	os << "<Character> " << rhs.getName() << " ";
	for ( int i = 0; i < rhs.getAmount(); i++ ) {
		os << rhs.getInventory( i )->getType() << ":" << rhs.getInventory( i )
		   << ( i < rhs.getAmount() ? ", " : "" );
	}

	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string const&	Character::getName( void ) const { return ( this->_name ); }

int	Character::getAmount( void ) const { return ( this->_amount ); }

AMateria*	Character::getInventory( int idx ) const {
	return ( this->_inventory[idx] );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	Character::equip( AMateria* m ) {

	if ( !m )
		std::cout << "Character <" << this->_name
				  << "> cannot equip from nullptr";
	else if ( this->_amount == 4 )
		std::cout << "Character <" << this->_name
				  << " has no more inventory space left";
	else {
		// Checking if m already exists in inventory
		for ( int i = 0; i < this->_amount; i++ ) {
			if ( this->_inventory[i] == m ) {

				std::cout << "Character <" << this->_name
				          << "> already equiped " << m->getType()
						  << ":" << m << std::endl;
				return ;
			}
		}

		this->_inventory[ this->_amount ] = m;
		std::cout << "Character <" << this->_name << "> equiped "
				  << m->getType() << ":" << m;
		this->_amount++;
	}
	std::cout << std::endl;
}

void	Character::unequip( int idx ) {

	if ( idx > 0 && idx < this->_amount ) {
		std::cout << "Character <" << this->_name << "> unequiped "
				  << this->_inventory[idx]->getType() << ":"
				  << this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void	Character::use( int idx, ICharacter& target ) {

	if ( idx < 0 || idx > this->_amount )
		return ;
	this->_inventory[idx]->use( target );
}
