/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:44:19 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/09/22 09:16:43 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

DiamondTrap::DiamondTrap( void ) : _name( "Diamond" ) {

    ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hp;
    this->_energy = ScavTrap::_ep;
    this->_attack = FragTrap::_ad;
	DEBUG( "Diamond <" << this->_name << "> default constructor called" );
}

DiamondTrap::~DiamondTrap( void ) {
	DEBUG( "Diamond <" << this->_name << "> destructor called" );
}

DiamondTrap::DiamondTrap( DiamondTrap const& src ) {

	*this = src;
	DEBUG( "Diamond <" << this->_name << "> copy constructor called" );
}

DiamondTrap::DiamondTrap( std::string name ) : _name( name ) {

    ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hp;
    this->_energy = ScavTrap::_ep;
    this->_attack = FragTrap::_ad;
	DEBUG( "Diamond <" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

DiamondTrap&	DiamondTrap::operator=( DiamondTrap const& rhs ) {

	ClapTrap::operator=( rhs );
	this->_name = rhs._name;

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, DiamondTrap const& rhs ) {

	os << "DiamondTrap <" << rhs.getName()
	   << "> Hit( " << rhs.getHit()
	   << " ); Energy( " << rhs.getEnergy()
	   << " ); Attack( " << rhs.getAttack()
	   << " );";

	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	DiamondTrap::getName( void ) const { return ( this->_name ); }

void	DiamondTrap::setName( std::string name ) { this->_name = name; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack( target );
}

void	DiamondTrap::whoAmI( void ) {

	std::cout << "DiamondTrap <" << this->_name << "> ClapTrap name is <"
			  << ClapTrap::_name << ">" << std::endl;
}
