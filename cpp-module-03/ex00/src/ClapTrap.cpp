/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:37:00 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 17:30:18 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* Contructors and Destructors                                                */
/* ************************************************************************** */

ClapTrap::ClapTrap( void ) : _hit( 10 ), _energy( 10 ), _attack( 0 ) {
	DEBUG( "<ClapTrap> default constructor called" );
}

ClapTrap::~ClapTrap( void ) { DEBUG( "<ClapTrap> destructor called" ); }

ClapTrap::ClapTrap( ClapTrap const& src ) {

	*this = src;
	DEBUG( "<ClapTrap> copy constructor called" );
}

ClapTrap::ClapTrap( std::string name )
	: _name( name ), _hit( 10 ), _energy( 10 ), _attack( 0 ) {
	DEBUG( "<" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operators Overload                                                         */
/* ************************************************************************** */

ClapTrap&	ClapTrap::operator=( ClapTrap const& rhs ) {

	this->_name = rhs._name;
	this->_hit = rhs._hit;
	this->_energy = rhs._energy;
	this->_attack = rhs._attack;

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, ClapTrap const& rhs ) {

	os << "ClapTrap <" << rhs.getName();
	os << "> Hit( " << rhs.getHit();
	os << " ); Energy( " << rhs.getEnergy();
	os << " ); Attack( " << rhs.getAttack() << ");";

	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	ClapTrap::getName( void ) const { return ( this->_name ); }

unsigned int	ClapTrap::getHit( void ) const { return ( this->_hit ); }

unsigned int	ClapTrap::getEnergy( void ) const { return ( this->_energy ); }

unsigned int	ClapTrap::getAttack( void ) const { return ( this->_attack ); }

void	ClapTrap::setName( std::string name ) { this->_name = name; }

void	ClapTrap::setHit( unsigned int hit ) { this->_hit = hit; }

void	ClapTrap::setEnergy( unsigned int energy ) { this->_energy = energy; }

void	ClapTrap::setAttack( unsigned int attack ) { this->_attack = attack; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	ClapTrap::attack( const std::string& target ) {

	std::cout << "ClapTrap " << this->_name << " ";

	if ( this->_energy == 0 )
		std::cout << "has no energy left!" << std::endl;
	else {

		std::cout << "attacks " << target << ", causing " ;
		std::cout << this->_attack << " points of damage!" << std::endl;
	}

	( this->_energy <= 5 ) ? ( this->_energy = 0 ) : ( this->_energy -= 5 );
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	( this->_hit <= amount ) ? ( this->_hit = 0 ) : ( this->_hit -= amount );

	std::cout << "ClapTrap " << this->_name << " took " << amount;
	std::cout << " points of damage";
	if ( this->_hit == 0)
		std::cout << " and was destroyed!";
	std::cout << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	this->_hit += amount;

	std::cout << "ClapTrap " << this->_name << " was repaired " << amount;
	std::cout << " points!" << std::endl;
}
