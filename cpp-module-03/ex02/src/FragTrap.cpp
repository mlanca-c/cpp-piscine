/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:21:28 by mlancac           #+#    #+#             */
/*   Updated: 2022/09/22 09:36:06 by mlanca-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

FragTrap::FragTrap( void ) : ClapTrap() {

	this->_name = "Frag";
	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	DEBUG( "FragTrap <" << this->_name << "> default constructor called" );
}

FragTrap::~FragTrap( void ) {
	DEBUG( "FragTrap <" << this->_name << "> destructor called" );
}

FragTrap::FragTrap( FragTrap const& src ) {

	*this = src;
	DEBUG( "FragTrap <" << this->_name << "> copy constructor called" );
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	this->_hitPoints = 100;
	this->_energy = 100;
	this->_attack = 30;
	DEBUG( "FragTrap <" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

FragTrap&	FragTrap::operator=( FragTrap const& rhs ) {

	ClapTrap::operator=( rhs );

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, FragTrap const& rhs ) {

	os << "FragTrap <" << rhs.getName()
	   << "> Hit( " << rhs.getHit()
	   << " ); Energy( " << rhs.getEnergy()
	   << " ); Attack( " << rhs.getAttack()
	   << " );";

	return ( os );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	FragTrap::attack( const std::string& target ) {

	std::cout << "FragTrap " << this->_name << " ";

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

void	FragTrap::highFiveGuys( void ) {

	std::cout << "FragTrap " << this->_name << " ";

	if ( this->_hitPoints == 0 )
		std::cout << "is dead and cannot ask for a high five";
	else if ( this->_energy == 0 )
		std::cout << "has no energy left and cannot ask for a high five";
	else {
		std::cout << "is requesting a positive high five";
		( this->_energy - 1 < 0 ) ?
			( this->_energy = 0 ) : ( this->_energy -= 1 );
	}
	std::cout << "!" << std::endl;
}
