/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanca-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:44:19 by mlanca-c          #+#    #+#             */
/*   Updated: 2022/06/29 13:03:12 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

DiamondTrap::DiamondTrap( void ) : _name( "DiamondTrap" ) {

    ClapTrap::_name = _name + "_clap_name";
    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy;
    this->_attack = FragTrap::_attack;
	DEBUG( "<DiamondTrap> default constructor called" );
}

DiamondTrap::~DiamondTrap( void ) { DEBUG( "<FragTrap> destructor called" ); }

DiamondTrap::DiamondTrap( DiamondTrap const& src ) {

	*this = src;
	DEBUG( "<FragTrap> copy constructor called" );
}

DiamondTrap::DiamondTrap( std::string name ) : _name( name ) {

    ClapTrap::_name = _name + "_clap_name";
    this->_hit = FragTrap::_hit;
    this->_energy = ScavTrap::_energy;
    this->_attack = FragTrap::_attack;
	DEBUG( "<" << this->_name << "> constructor called" );
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

	os << "DiamondTrap <" << rhs.getName();
	os << "> Hit( " << rhs.getHit();
	os << " ); Energy( " << rhs.getEnergy();
	os << " ); Attack( " << rhs.getAttack();
	os << " );";

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
	FragTrap::attack( target );
}

void	DiamondTrap::whoAmI( void ) {

	std::cout << "DiamondTrap <" << this->_name << "> ClapTrap name is <";
	std::cout << ClapTrap::_name << ">" << std::endl;
}
