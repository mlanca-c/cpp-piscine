/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:49:20 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/20 11:32:54 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* Static Attributes                                                          */
/* ************************************************************************** */

int const       ScavTrap::_hp = 100;
int const       ScavTrap::_ep = 50;
int const       ScavTrap::_ad = 20;

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

ScavTrap::ScavTrap( void ) : _gateMode( false ) {

	this->_name = "Scav";
	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	DEBUG( "ScavTrap <" << this->_name << "> default constructor called" );
}

ScavTrap::~ScavTrap( void ) {
	DEBUG( "ScavTrap <" << this->_name << "> detructor called" );
}

ScavTrap::ScavTrap( ScavTrap const& src ) : ClapTrap( src ) {

	*this = src;
	DEBUG( "ScavTrap <" << this->_name << "> copy constructor called" );
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ), _gateMode( false ) {

	this->_hitPoints = 100;
	this->_energy = 50;
	this->_attack = 20;
	DEBUG( "ScavTrap <" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

ScavTrap&	ScavTrap::operator=( ScavTrap const& rhs ) {

	ClapTrap::operator=( rhs );
	this->_gateMode = rhs._gateMode;

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, ScavTrap const& rhs ) {

	os << "ScavTrap <" << rhs.getName()
	   << "> Hit( " << rhs.getHit()
	   << " ); Energy( " << rhs.getEnergy()
	   << " ); Attack( " << rhs.getAttack()
	   << " ); GateKeeper Mode( " << ( rhs.getGateMode() ? "true" : "false" )
	   << " );";

	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

bool	ScavTrap::getGateMode( void ) const { return ( this->_gateMode ); }

void	ScavTrap::setGateMode( bool gateMode ) { this->_gateMode = gateMode; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	ScavTrap::attack( const std::string& target ) {

	std::cout << "ScavTrap " << this->_name << " ";

	if ( this->_hitPoints == 0 ) std::cout << "is dead and cannot attack";
	else if ( this->_gateMode )
		std::cout << "is guarding the gate and cannot attack";
	else if ( this->_energy == 0 )
		std::cout << "has no energy left and cannot attack";
	else {

		std::cout << "attacks " << target << ", causing " ;
		std::cout << this->_attack << " points of damage";
		this->_energy--;
	}
	std::cout << "!" << std::endl;
}

void	ScavTrap::guardGate( void ) {

	( this->_gateMode ? this->_gateMode = false : this->_gateMode = true );
	std::cout << "ScavTrap " << this->_name << " ";
	if ( this->_gateMode )
		std::cout << "is now in gatekeeper mode" << std::endl;
	else
		std::cout << "is no longer in gatekeeper mode" << std::endl;
}
