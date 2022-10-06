/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:37:00 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/20 11:22:13 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ************************************************************************** */
/* Contructors and Destructors                                                */
/* ************************************************************************** */

ClapTrap::ClapTrap( void )
	: _name( "Clap" ), _hitPoints( 10 ), _energy( 10 ), _attack( 0 ) {
	DEBUG( "ClapTrap <" << this->_name << "> default constructor called" );
}

ClapTrap::~ClapTrap( void ) {
	DEBUG( "ClapTrap <" << this->_name << "> destructor called" );
}

ClapTrap::ClapTrap( ClapTrap const& src ) {

	*this = src;
	DEBUG( "ClapTrap <" << this->_name << "> copy constructor called" );
}

ClapTrap::ClapTrap( std::string name )
	: _name( name ), _hitPoints( 10 ), _energy( 10 ), _attack( 0 ) {
	DEBUG( "ClapTrap <" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operators Overload                                                         */
/* ************************************************************************** */

ClapTrap&	ClapTrap::operator=( ClapTrap const& rhs ) {

	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energy = rhs._energy;
	this->_attack = rhs._attack;

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, ClapTrap const& rhs ) {

	os << "ClapTrap <" << rhs.getName()
	   << "> Hit( " << rhs.getHit()
	   << " ); Energy( " << rhs.getEnergy()
	   << " ); Attack( " << rhs.getAttack() << " );";

	return ( os );
}

/* ************************************************************************** */
/* Getters and Setters                                                        */
/* ************************************************************************** */

std::string	ClapTrap::getName( void ) const { return ( this->_name ); }

unsigned int	ClapTrap::getHit( void ) const { return ( this->_hitPoints ); }

unsigned int	ClapTrap::getEnergy( void ) const { return ( this->_energy ); }

unsigned int	ClapTrap::getAttack( void ) const { return ( this->_attack ); }

void	ClapTrap::setName( std::string name ) { this->_name = name; }

void	ClapTrap::setHit( unsigned int hit ) { this->_hitPoints = hit; }

void	ClapTrap::setEnergy( unsigned int energy ) { this->_energy = energy; }

void	ClapTrap::setAttack( unsigned int attack ) { this->_attack = attack; }

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	ClapTrap::attack( const std::string& target ) {

	std::cout << "ClapTrap <" << this->_name << "> ";

	if ( this->_hitPoints == 0 ) std::cout << "is dead and cannot attack";
	else if ( this->_energy == 0 )
		std::cout << "has no energy left and cannot attack";
	else {

		std::cout << "attacks " << target << ", causing " ;
		std::cout << this->_attack << " points of damage";
		this->_energy--;
	}
	std::cout << "!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	std::cout << "ClapTrap <" << this->_name << "> ";

	if ( this->_hitPoints == 0 ) std::cout << "is dead and cannot take "
										   << "any more damage";
	else {

		( this->_hitPoints <= amount )
			? ( this->_hitPoints = 0 ) : ( this->_hitPoints -= amount );
		std::cout << "took " << amount << " points of damage";
		if ( this->_hitPoints == 0) std::cout << " and was destroyed";
	}
	std::cout << "!" << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	std::cout << "ClapTrap <" << this->_name << "> ";

	if ( this->_hitPoints == 0 )
		std::cout << "is dead and cannot be repaired";
	else if ( this->_energy == 0 )
		std::cout << "has no energy left and cannot be repaired";
	else {

		std::cout << "was repaired " << amount << " points";
		this->_hitPoints += amount;
		this->_energy--;
	}
	std::cout << "!" << std::endl;
}
