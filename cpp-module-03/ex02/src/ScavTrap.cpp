/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:49:20 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/29 12:33:31 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

ScavTrap::ScavTrap( void ) : ClapTrap(), _gateMode( false ) {

	this->_name = "ScavTrap";
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 50;
	DEBUG( "<ScavTrap> default constructor called" );
}

ScavTrap::~ScavTrap( void ) { DEBUG( "<ScavTrap> destructor called" ); }

ScavTrap::ScavTrap( ScavTrap const& src ) {

	*this = src;
	DEBUG( "<ScavTrap> copy constructor called" );
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ), _gateMode( false ) {

	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 50;
	DEBUG( "<" << this->_name << "> constructor called" );
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

	os << "ScavTrap <" << rhs.getName();
	os << "> Hit( " << rhs.getHit();
	os << " ); Energy( " << rhs.getEnergy();
	os << " ); Attack( " << rhs.getAttack();
	os << " ); GateKeeper Mode( " << ( rhs.getGateMode() ? "true" : "false" );
	os << " );";

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

	if ( this->_energy == 0 )
		std::cout << "has no energy left and cannot attack!";
	else if ( this->_hit == 0 )
		std::cout << "has no hit points left and cannot attack!";
	else {

		std::cout << "attacks " << target << ", causing " ;
		std::cout << this->_attack << " points of damage!";
		this->_hit--;
		this->_energy--;
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate( void ) {

	( this->_gateMode ? this->_gateMode = false : this->_gateMode = true );
	std::cout << "ScavTrap " << this->_name << " ";
	std::cout << "is now in gatekeeper mode" << std::endl;
}
