/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlancac </var/spool/mail/mlancac>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:21:28 by mlancac           #+#    #+#             */
/*   Updated: 2022/06/26 17:31:30 by mlancac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */

FragTrap::FragTrap( void ) : ClapTrap() {

	this->_name = "FragTrap";
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	DEBUG( "<FragTrap> default constructor called" );
}

FragTrap::~FragTrap( void ) { DEBUG( "<FragTrap> destructor called" ); }

FragTrap::FragTrap( FragTrap const& src ) {

	*this = src;
	DEBUG( "<FragTrap> copy constructor called" );
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ) {

	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
	DEBUG( "<" << this->_name << "> constructor called" );
}

/* ************************************************************************** */
/* Operator Overload                                                          */
/* ************************************************************************** */

FragTrap&	FragTrap::operator=( FragTrap const& rhs ) {

	ClapTrap::operator=( rhs );

	return ( *this );
}

std::ostream&	operator<<( std::ostream& os, FragTrap const& rhs ) {

	os << "FragTrap <" << rhs.getName();
	os << "> Hit( " << rhs.getHit();
	os << " ); Energy( " << rhs.getEnergy();
	os << " ); Attack( " << rhs.getAttack();
	os << " );";

	return ( os );
}

/* ************************************************************************** */
/* Other Functions                                                            */
/* ************************************************************************** */

void	FragTrap::highFiveGuys( void ) {

	std::cout << "FragTrap " << this->_name << " ";
	std::cout << "is requesting a positive high five!" << std::endl;
}

